### ====1.安装deb包====
- ` sudo dpkg -i file.deb `

***
### ====2.修改删除文件名====
  * `rm old.file new.file`
  * `rename`
  * `remove`
  * 链接 `symlink` 原路径 符号链接名
  * `access`  检查权限

***
### ====3.显卡驱动生效====
- `glxinfo | head`

### ====4.vim下复制粘贴剪切====
* `yy`复制一行
* `5yy`复制5行
* `p`粘贴
* `d`是剪切
* 可视模式`v`

***
### ====5.vim常用命令====
- : `w 【filename】`将编辑的数据存储为另一个文件
- : `r 【filename】`将读入文件的数据加到当前游标后面
- : `!command`暂时离开`vim`
- 多次按`u` 恢复 按`ctrl+r`是再次恢复
- :`sp` 是分割`vim`
***
### ====6.打开图片====
- shotwell

### ====7.进程和杀死进程====
- `kill PID`
- `kill-TERM PID` 杀死它和它的子进程
- `ps -f -l -e`  显示进程
- `ctrl +Z` 暂停当前进程

### ====8.清理垃圾====
 * `sudo apt-get autoremove` //自动卸载不使用的内容
 * `sudo apt-get autoclean` //自动清理，但不会删除用于安装而下载的临时文件
 * `sudo apt-get clean` //清理下载的临时文件

### ====9.解压缩包====
1. `tar -zxvf /*.tar.gz` /解压到此目录   解压
 * **.gz**
    - 解压1：`gunzip FileName.gz`
    - 解压2：`gzip -d FileName.gz`
    - 压缩： `gzip FileName`
 * **.tar.gz**
    - 解压：`tar -zxvf FileName.tar.gz`
    - 压缩：`tar -zcvf FileName.tar.gz DirName`

 * **.bz2**
    - 解压1：`bzip2 -d FileName.bz2`
    - 解压2：`bunzip2 FileName.bz2`
    - 压缩： `bzip2 -z FileName`
 * **.tar.bz2**
    - 解压：`tar -jxvf FileName.tar.bz2`
    - 压缩：`tar -jcvf FileName.tar.bz2 DirName`

 * **.bz**
    - 解压1：`bzip2 -d FileName.bz`
    - 解压2：`bunzip2 FileName.bz`
    - 压缩：未知
 * **.tar.bz**
    - 解压：`tar -jxvf FileName.tar.bz`
    - 压缩：未知

 * **.Z**
    - 解压：`uncompress FileName.Z`
    - 压缩：`compress FileName`
 * **.tar.Z**
    - 解压：`tar -Zxvf FileName.tar.Z`
    - 压缩：`tar -Zcvf FileName.tar.Z DirName`

 * **.tgz**
    - 解压：`tar -zxvf FileName.tgz`
    - 压缩：未知
 * **.tar.tgz**
    - 解压：`tar -zxvf FileName.tar.tgz`
    - 压缩：`tar -zcvf FileName.tar.tgz FileName`

 * **.zip**
    - 解压：`unzip FileName.zip`
    - 压缩：`zip FileName.zip DirName`

 * **.rar**
    - 解压：`rar` `-a FileName.rar`
    - 压缩：`rar` `-e FileName.rar`
---
### ====10.设置PATH====
* `export PATH=$PATH:the path you set`
* `PATH` 可以替换任何路径 `LD_LIBRARY`
* 永久设置  `vim ~/.bashrc`   `PATH=$PATH:the path you set`

### ====11.tmux 基本操作====
* `tmux = ctrl+a`
* `tmux + esc` 滚屏

### ====12.磁盘大小====
* `df -hl` 查看磁盘剩余空间
* `df -h` 查看每个根路径的分区大小
* `du -sh` [目录名] 返回该目录的大小
* `du -sm` [文件夹] 返回该文件夹总M数

### ====13.搜索文件====
* `which -a command/`配置文件`config`
 * `type` 类似`which`，`bash`专有
* `whereis` 寻找特定文件（模糊）
* `locate` 类似`whereis`，找不到数据库更新前的文件，默认Linux每天更新一次,可以自行更新`updatedb`
* `find` 精确，慢

### ====14.权限设置====
1. **群组更改**：`chgrp`  新的群组（存在的）  文件
2. **文件拥有者**：`chown` 拥有者：群组 `-R`（改目录下所有次目录或文件同时更改） 文件
	`chown` .群组 `-R`（改目录下所有次目录或文件同时更改） 文件
3. **chmod**
![权限](./pic/access.png)

  * 权限身份：`u g o a`（所有）
  || +(加入)
  -(除去)
  =(设定)
  || `r w x`
  文件或目彔

  * `chmod 777 file`
  * `chmod  u=rwx,go=rx  .bashrc`
  * `chmod a+w .bashrc`
