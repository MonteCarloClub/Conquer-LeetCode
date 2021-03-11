# LeetCode-in-Go

我已经把仓库从个人账户迁移到了组织账户，一起记录我们的刷题之路吧！

## 力扣（LeetCode）官网

https://leetcode-cn.com

## 怎么加入我们？

0. 如果你已经克隆了这个仓库，那么请重新设置远程仓库地址：
```dotnetcli
git remote set-url origin https://github.com/XINKINGBO-1206/Conquer-LeetCode.git
```
完成后请跳到步骤2；

1. 克隆这个仓库到本地：
```dotnetcli
git clone https://github.com/XINKINGBO-1206/Conquer-LeetCode.git
```

2. 新建自己的分支同时切换过去：
```dotnetcli
git checkout -b <你的分支名>
```
你在自己分支上的工作不会影响主分支和他人的分支。这时候，你可以选择清空自己的分支（它可能初始地包含主分支上他人的贡献）并提交：
```dotnetcli
git add .
git commit -m "Clean my branch"
```

3. 把自己的分支推送到远程仓库：
```dotnetcli
git push -u origin <你的分支名>
```
如果失败，可以尝试强制推送使远程仓库跟本地保持一致：
```dotnetcli
git push -f origin <你的分支名>
```
简单回顾一下，把本地更改提交到GitHub上分成3步：add（缓存）->commit（提交）->push（推送），请不要直接向主分支或他人的分支推送更改；

4. 有且仅有正确答案被允许归并到主分支，请在合适的时候提出pull request，管理员审核通过后即合并。

## 注意事项
记得及时更新自己的
```.gitignore```
文件，不要把无关文件推送到远程仓库，保持整洁，人人有责。

关于
```.gitignore```
的规范写法，请参阅：
https://git-scm.com/docs/gitignore
。