# 알고리즘 스터디
> [바킹독의 실전 알고리즘 강의](https://www.youtube.com/playlist?list=PLtqbFd2VIQv4O6D6l9HcD732hdrnYb6CY)
> 
> [백준 온라인 저지 (Code.Plus)강의](https://code.plus/)
> 
> [FastCampus 류호석 강의](https://fastcampus.co.kr/)

# 문제 및 풀이
 주제 | 진행도 |  
 :--: | :--: |
[자료구조](/자료구조/solution.md) | ![100%](https://progress-bar.dev/24/?scale=61&title=progress&width=500&color=babaca&suffix=/61) |
[탐색 알고리즘](/탐색/solution.md) | ![100%](https://progress-bar.dev/6/?scale=88&title=progress&width=500&color=babaca&suffix=/88) |
[알고리즘 기법](/알고리즘기법/solution.md) | ![100%](https://progress-bar.dev/5/?scale=91&title=progress&width=500&color=babaca&suffix=/91) |
[수학적 개념](/수학/solution.md) | ![100%](https://progress-bar.dev/0/?scale=39&title=progress&width=500&color=babaca&suffix=/39) |

# Git 기본 사용
> [GitHub-Practice Site](https://learngitbranching.js.org/?locale=ko)
+ 기본
```
$ git clone https://github.com/jihwankim128/algorithm.git
$ git remote add "원격저장소명" https://github.com/jihwankim128/algorithm.git
$ git chekcout main    
// defalut branch가 master인 경우, 최신 installer 설정에 따라 다름. main일 경우 무시
```
+ 작업
```
$ cd 작업한 경로
$ git add <fileName> 
또는
$ git add . 
// git add . 의 경우 원하는 commit message를 작성하기 힘든 단점이 있음.
$ git commit -m "Message"
$ git push <remoteName> main
```
+ Auto Merge (git push시 collision 이 발생할 때)
```
$ git pull <remoteName>  
// 이전에 누군가 작업 후 pull 시 자동 Merge 해줌
// 동일한 파일에 작업을 했을 경우 충돌되어 충돌된 파일을 재수정해야함.
// 파일 수정 후
$ git add .
$ git commit -m " "
$ git push <remote> <branch>
```
+ 사전 충돌 방지
```
$ git fetch <remote> //활용
$ git checkout <newbranch>
$ git push <remote> <newBranch>
// 이후 github remote에서 수동으로 Pull Requests
```
