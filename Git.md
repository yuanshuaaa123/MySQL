# Git基本操作命令
## 安装GIT工具
```shell
sudo apt-get install git
```
## 创建版本库
创建一个用来存放仓库的目录，执行git init命令，创建git仓库
```shell
mkdir html
cd html
git init
```
创建成功后使用ls -al命令查看仓库中文件，有隐藏的.git目录，注意这存放着git管理工具用到的所有信息和基本配置信息，不可手动修改，否则会破坏仓库
## 提交文件
当前目录暂无文件，先创建一个文件README，对其进行编辑
```shell
touch README
vim README
```
查看仓库状态，红色表示未添加，绿色表示已添加
```shell
git status
```
将其添加进仓库
```shell
git add README
git add . //注意这是将当前目录所有文件全部添加进仓库
```
提交到仓库里进行保存
```shell
git commit //需要填写记录日志文档，注意应简洁明了的描述提交的该文件
```
## 从版本库中忽略文件
```shell
touch .gitignore
vim .gitignore //将需要忽略的文件添加到其中，版本库也会将其忽略
```
## 配置用户信息
配置用户名, 一般为注册的GitHub用户名
```shell
git config --global user.name
```
配置用户邮箱, 一般为和GitHub绑定的最常用的邮箱
```shell
git config --global user.email
```
配置编辑提交信息的编辑器vim
```shell
git config --global core.editor vim
```

## 查看提交信息
```shell
git log //查看提交的文件日志信息
git reflog //查看所有提交的历史记录
```
## 删除文件恢复
有时候, 我们不小心把文件给删除了. 想恢复这个文件时, 需要用到下面的命令.

删除文件
```shell
git rm filename //删除仓库里的文件,但并未真正删除
git commit //提交后才算真正删除
```
把仓库里的README这个文件给删除了. 然后再使用ls命令查看文件, 看看这个文件是否还存在.
```shell
rm README //删除README文件
ls //查看目录中文件
ls -al //查看目录中所有文件，包括隐藏文件
```
查看仓库状态
```shell
git status
```
发现这个文件是误删了, 我们想把它恢复回来, 如果没有将这个文件提交到仓库里, 无法将它恢复.
只要将文件提交到仓库中，便可对其进行恢复，可利用ID/commitID对其进行恢复
```shell
git checkout README
git reset --hard commitID //利用ID对其进行恢复
```
再查看文件是否存在，并查看仓库状态
```shell
ls -al
git status
```
## 进行版本之间的对比
查看提交的文件修改的地方,便可清晰明了的知道对文件所做的改动
```shell
git diff
git diff commitID1 commitID2
```
## patch
patch多指补丁的意思, 在这里更多的指程序有一些bug, 需要我们进行fixed, 那fixed源码文件就是patch.

patch实际上是保存两个文件的差异.一个patch保存一次修改或删除之后两个文件的差异

git生成patch
```shell
git format-patch -p1 //生成补丁包，p1则生成1个补丁包，p5则生成5个补丁包，前提是已经进行到5次修改或删除操作
```
git 打patch
```shell
git am patch-name //利用该patch将文件恢复到之前的版本
```


# Git分支Workflow
## 创建分支
现在我们就使用下面的命令去创建一个分支. 这个命令只是创建并没有切换到新创建的分支上. git仓库初始化创建的时候, 会为我们自动创建一个master的主分支.
```shell
git branch branch-name
```
可以从任何的地方创建分支, 并切换到新创建的分支上.
```shell
git checkout -b branch-name
```
## 显示分支
如果我们想要显示当前git仓库中有多少个分支.
```shell
git branch -av
```
## 分支切换
如果我们想从A分支切换到B分支使用下面的命令.
```shell
git checkout branch-name
```
## 删除分支
如果我们要删除一个分支, 那么我们一定要站在另一个分支上去删除它. 也就是说不能删除当前所在的分支.
```shell
git branch -D branch-name
```
## 合并分支 
### merge
我们将`develop`分支开发的提交, 合并到`master`分支上.
```shell
git checkout master
git merge develop
```
如果出现冲突的时候可以使用`mergetool`, 解决冲突.
```shell
git mergetool
```
### rebase
现在我们决定把`develop`分支的变化也包含进来。我们可以直接把 `develop` 分支衍合到 `master`，而不用手工切换到 `develop` 分支后再执行衍合操作 — `git rebase [主分支] [特性分支]` 命令会先取出特性分支 `develop master` 上重演：
```shell
git rebase master develop
```
### cherry-pick
用`cherry-pick`取出提交，然后将其添加到当前分支上, 你当前处在那个分支上就是放到相应的分支上.
```shell
git cherry-pick <commit-id>
```
如果出现冲突,就正常解决冲突, 然后进行重新提交.
## 什么是标签
标签是为了更方便地参考提交而给它标上易懂的名称。Git可以使用2种标签：轻标签和注解标签。打上的标签是固定的，不能像分支那样可以移动位置。
### 创建标签
使用tag命令来添加标签. 是要创建标签的名称.
```shell
git tag <tag-name>
```
还可以根据commit ID创建标签.
```shell
git tag <tag-name> <commit ID>
```
### 显示tag标签信息
如果没有输入要创建标签的名子, 它就会显示现在所有的标签.
```shell
git tag
```
如果在log命令添加 –decorate选项执行，可以显示包含标签资料的历史记录。
```shell
git log --decorate
```
可以显示从tag开始的所有提交信息.
```shell
git log tag-name
```
可能显示tag的提交信息和提交的内容及patch.
```shell
git show tag-name
```
### checkout 分支
可以根据tag的标记来进行创建分支.
```shell
git checkout -b branch-name tag-name
```
### 删除标签
若要删除标签，在tag命令指定 -d选项执行。
```shell
git tag -d <tagname>
```


# 使用远程仓库
## 将本地仓库添加到远程仓库中
如果我们现在本地有一个git仓库, 我们使用remote add 命令将它添加到远程的仓库中.
```shell
git remote add origin 远程的url地址
```
并需要将远程的仓库的信息更步到本地, 这里主要指的示远程仓库的分支和远程库的提交变更信息.
```shell
git fetch origin
```
## 向远程仓库提交
### 同步master分支
如果我们本地的仓库进行开发, 交进行提交commit. 那么我们本地的仓库和远程的仓库就不能保持同步了.那么我们需要把本地的这次提交也要反映在远程的仓库上. 那么我们就需要使用push命令.
```shell
git push origin master
```
### 同步其它分支
如果我们需要我们其它分支的提交也要反映在远程库中. 如果远程没有这个分支, 它就会自动创建这个分支.
```shell
git push origin branch-name
```
### 同步标签

使用git push origin branch-name命令不会将本地打好的标签同步(推送)到服务器上, 需要使用下面的命令将本地的tags同步(推送)到服务器上.
```shell
git push origin --tags
```
### 删除远程分支
可以用这个非常有意思的语法来删除它：git push [远程名] :[分支名]。 在于分支名前的冒号.
```shell
git push -u origin :branch-name
```
### 删除远程标签
如果我们也想把远程仓库中是的标签删除.
```shell
git push origin --delete <branchName>
git push origin --delete tag <tagname>
```
## 从远程仓库同步
### 将远程仓库克隆到本地仓库
```shell
git clone 该远程仓库的url地址
```
### 将服务器和本地进行实时源码同步
```shell
git pull
```
