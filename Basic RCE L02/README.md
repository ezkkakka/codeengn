## Basic RCE L02  
패스워드로 인증하는 실행파일이 손상되어 실행이 안되는 문제가 생겼다. 패스워드가 무엇인지 분석하시오  

bin - binary file  

해당 바이너리를 실행하면 실제로 실행이 안됩니다.  
Hex Editor를 통해 바이너리 코드를 확인해보면 다음과 같습니다.  

![image](https://github.com/ezkkakka/driver/assets/118009522/e8394435-235a-4d51-8e17-39dbe0b6417c)  

![ce02](https://github.com/ezkkakka/driver/assets/118009522/5fca2f1d-0c02-43c4-9016-050d7f1908c6)  

사용하는 API 이름이 보이고 아래 사진을 보면 문자열이 저장되어 있는 것 같은데 그 중, JK3FJZh 문자열이 패스워드입니다.  