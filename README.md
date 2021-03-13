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

2. **新建你的目录**，在你自己的目录下工作：
```dotnetcli
cd Conquer-LeetCode
mkdir <YOUR_NAME>-<LANG>
```
请保持在自己的目录下工作，这不会影响他人的工作。

*事实上，最好的解决方案是各自在不同的分支上工作，最后合并到主分支。因为我们的提交信息包含了“#题目编号”这样的写法，这样的写法会不必要地应用PR或Issues，所以我不鼓励在本项目提交PR和Issue。*

你可以随时提交你的更改：
```dotnetcli
git add .
git commit -m "write a message here"
```

3. 把自己的分支推送到远程仓库：
```dotnetcli
git push -u origin master
```

**假如失败，请勿强制推送，请检查和解决冲突！**

简单回顾一下，把本地更改提交到GitHub上分成3步：add（缓存）->commit（提交）->push（推送），请不要直接向主分支或他人的分支推送更改；


## 注意事项
记得及时更新
```.gitignore```
文件，不要把无关文件推送到远程仓库，保持整洁，人人有责。

关于
```.gitignore```
的规范写法，请参阅：
https://git-scm.com/docs/gitignore
。