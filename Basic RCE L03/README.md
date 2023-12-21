## Basic RCE L03  
비주얼베이직에서 스트링 비교함수 이름은?  

bin - binary file  
src - source file  

![LCE03-0](https://github.com/ezkkakka/codeengn/assets/118009522/7b56eed2-6263-4662-8ef2-089d834ba8bb)  

프로그램을 실행하고 임의의 코드를 입력하면 위와 같이 에러 메시지가 발생합니다.  

![RCE03-1-1](https://github.com/ezkkakka/codeengn/assets/118009522/c5ecefad-4d38-4697-b74b-47658f8cba0e)  

__vbaStrCmp 함수가 문자열 비교 함수 같은데 해당 함수에 BP를 걸어 실제로 확인 해보면  

![RCE03-1-2](https://github.com/ezkkakka/codeengn/assets/118009522/44ae380d-986f-4b6f-be42-a2ce1ff6cbca)  

__vbaStrComp 함수를 호출하는데 함수로 들어가면 아래와 같이 나타납니다.  

![RCE03-2](https://github.com/ezkkakka/codeengn/assets/118009522/9f9927e5-9313-4633-99e7-3d6e6e473b8d)  

사용자가 입력한 문자열과 비교할 문자열의 길이를 ESI, EDI에 저장 후 비교합니다.  

![RCE03-3](https://github.com/ezkkakka/codeengn/assets/118009522/0f7dc0cc-b9f1-4828-876f-cf878e946ff4)  

![RCE03-4](https://github.com/ezkkakka/codeengn/assets/118009522/203a87f0-a5ea-4edc-bea6-c0fcb77b92da)  

---  
문제의 핵심은 문자열 비교 함수이므로 vbaStrCmp 입니다.  