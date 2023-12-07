## Basic RCE L01  
HDD를 CD-Rom으로 인식시키기 위해서는 GetDriveTypeA의 리턴값이 무엇이 되어야 하는가  

bin - binary file  
src - source file  

![x32](https://github.com/ezkkakka/echo-poc/assets/118009522/a34aa8a3-afd0-4a8c-9b4c-00f1ab5ed151)

```cpp
UINT GetDriveTypeA(
  [in, optional] LPCSTR lpRootPathName
);

반환 값:
DRIVE_UNKNOWN (0) - 드라이브 유형을 확인할 수 없음
DRIVE_NO_ROOT_DIR (1) - 루트 경로가 잘못됨
DRIVE_REMOVABLE (2) - 이동식 미디어가 있음 e.g. a floppy drive, thumb drive, or flash card reader.
DRIVE_FIXED (3) - 고정 미디어가 있음 e.g. a hard disk drive, solid-state drive, or flash drive.
DRIVE_REMOTE (4) - 원격(네트워크) 드라이브
DRIVE_CDROM (5) - CD-ROM 드라이브
DRIVE_RAMDISK (6) - RAM 디스크
```  

예제로 작성된 코드를 통해 설명하면 결국 esi 값을 eax 값과 맞춰야함.  
문제가 의도한건지 모르겠으나 esi 값은 AddressOfEntryPoint 값이 들어있기에 동적 분석으로 값의 조정이 필요한듯?  

**제가 문제 해석을 잘못한건지 애초에 GetDriveTypeA API에서의 리턴값이 5가 되어야 CD-ROM으로 인식한건데 제가 본 어셈 코드에선 cmp 코드 실행 전 eax = 1, esi = 4010003으로 전혀 의미없는 값이 나옴 (아마 여기서 esi++, eax-- 를 변경하라는 의도가 아니였는지) 그냥 API 리턴 값과 관계없이 eax, esi 값만 같게하면 CD-ROM으로 인식했다는 MessageBoxA API를 호출함**