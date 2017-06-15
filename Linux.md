# Linux基本命令

## 基本的文件操作

创建文件：touch  file
复制文件：cp file file1
cp file  /home/linux/file1
重命名文件：mv file   file2
移动文件：mv file  /home/linux/
删除文件：rm  -rf file
列出文件列表：ls -al  
查看文件内容：cat  file

## 基本的目录操作

创建目录：mkdir dir
复制目录：cp dir   dir1  -a
cp dir   /home/linux/dir2  -a
重命名目录：mv dir  dir2
移动目录：mv dir  /home/linux/
删除目录：rm  dir  -rf
列出目录列表：ls -d  dir
目录中查找文件：find  ./dir  -name  "filename"

## 文件的归档和压缩

使用gzip和bzip2对文件进行压缩
gzip  filename
bzip2  filename
使用gunzip和bunzip2对文件进行解压缩
gunzip filename
bunzip2  filename
使用tar对文件和目录进行压缩和解压缩
tar czvf  file.tar.gz dir
tar cjvf  file.tar.bz2 dir
tar cJvf  file.tar.xz  dir
tar xvf  file.tar.gz
tar xvf  file.tar.xz

## 安装VIM工具和GitHub工具

安装VIM工具：sudo apt-get install vim
安装GitHub工具：sudo apt-get install git

## 文本编辑器Vim的基本使用

* i：在当前字符的左边插入
* I：在当前行首插入
* a：在当前字符的右边插入
* A：在当前行尾插入
* o：在当前行下面插入一个新行
* O：在当前行上面插入一个新
* h: 向前移动一个字符
* j: 向下移动一行
* k: 向上移动一行
* l: 向后移动一个字符
* yy: 复制当前一行
* dd:剪切/删除当前一行
* p: 粘贴内容到游标之后
* P: 粘贴内容到游标之前
 
 ### 补充：
 
 vim file若该文件不存在则创建并编辑，若该文件已存在则直接进行编辑
 gcc hello.c -o hello执行hello.c文件
 ./hello执行hello文件，在品目上显示输出结果
 cd /进入跟目录
 cd 进入本地home目录
