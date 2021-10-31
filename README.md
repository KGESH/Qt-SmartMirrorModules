# QT Smart Mirror

---

## Description

- 라즈베리파이에서 실행되는 Smart Mirror App
- 주요 기능
  - Covid19 daily graph
  - Naver news headline
  - Date / Time

## How to setup

1. https://github.com/UvinduW/Cross-Compiling-Qt-for-Raspberry-Pi-4 참조

- 이때 QT Creator는 나중에 설치

2. 공식 홈페이지에서 qt 설치파일 다운후 설치진행

- 버전은 5.15.0
- 설치하면 QT Creator 자동으로 설치되는데 QT Creator 실행안되면 아래 명령어로 설치
<pre>sudo apt install qtcreator</pre>
- 공식 홈페이지에서 설치가 너무 느리면 미러서버에서 설치
  - https://blog.naver.com/chandong83/221845293395 참조

3. 설치된 QT Creator에서 데스크탑에서 빌드하는 키트와 라즈베리파이에서 빌드하는 키트 생성해줘야함

- 데스크탑 키트는 만들어져있을 테니 라즈베리파이 키트 만들어줘야 함
- https://velog.io/@kkywalk2/%EB%9D%BC%EC%A6%88%EB%B2%A0%EB%A6%AC%ED%8C%8C%EC%9D%B4%EB%A1%9C-Qt5-%ED%81%AC%EB%A1%9C%EC%8A%A4-%EC%BB%B4%ED%8C%8C%EC%9D%BC-%ED%99%98%EA%B2%BD-%EB%A7%8C%EB%93%A4%EA%B8%B0 참조

  - 키트 만드는건 여기 중간부분 IDE설정 참조 우리꺼랑 살짝 다르지만 큰 문제는 없음
  - 우리가 건드려야할건 device 탭에서 라즈베리파이 추가

- 컴파일러탭에서 1번의 깃허브 경로대로 했다면 /home/계정/rpi/tools/gcc-li뭐시기/bin 에서 gcc랑 g++ 등록

  - 이때 abi는 커스텀 - 암 - 리눅스 - 제네릭 - 엘프 - 32비트, 커스텀 선택하면 그냥 저렇게 될 거임

- QT 버전탭에서 qmake 파일 추가해줘야함

  - 기본 데스크탑 빌드환경 qmake가 있을텐데 라즈베리파이용 qmake 추가해줘야함
  - 1번의 깃허브 경로대로라면 /home/계정/rpi/qt5.15/bin/ 여기에 qmake 있음. 이거 추가

- 디바이스, 컴파일러, qmake까지 추가했으면 키트탭에서 add선택
- 이름, 디바이스 타입, sysroot, 컴파일러, 디버거, qt버전 설정해 주기

  - 이때 sysroot는 1번 깃헙 경로대로면 /home/계정/rpi/sysroot 임
    - 컴파일러 우리가 설정한 크로스컴파일러 넣어줌
    - qt버전도 등록한 것 넣어줌

- 이대로하면 라즈베리파이용 키트 생성 끝

4.  QT Creator 에서 프로젝트 만들고 데스크탑용 키트, 라즈베리파이용 키트 둘다 선택하고 프로젝트 빌드 후 실행해보기
    - 이때 내 경우에는 데스크탑 키트 실행할때
      <pre>:-1: error: cannot find -lGL</pre> 이런 에러나면서 빌드가 안됐음
      - https://stackoverflow.com/questions/13701551/qt-error-cannot-find-libs/53866171
        - 참고해서 해결

## Important

- 라즈베리파이 빌드할때는 .pro 파일에 라즈베리파이에 배포 할 경로를 써줘야 함
- 3번 링크 아래쪽에 프로젝트 생성 및 배포 참조

- 라즈베리파이 키트로 빌드하고 실행하면 라즈베리파이에서 바로 실행이 안될텐데
- https://www.youtube.com/watch?v=TmtN3Rmx9Rk&ab_channel=UlasDikme 영상 44:53부터 참고
- 그대로 따라하면 라즈베리파이에서 바로 실행됨

## Environment

- Dev / Build

  - Ubuntu 18.04 (x86)
  - GNU Toolchain

- Target

  - Raspbian Kernel 5.4.51 (ARM)

- C++
- QT
