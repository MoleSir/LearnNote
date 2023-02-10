# Git 分支

几乎每一种版本控制系统都以某种形式支持分支，一个分支代表一条独立的开发线。

使用分支意味着可以从开发主线上分离开来，然后在不影响主线的同时继续工作。

<img src="pics/7-Git分支.assets/image-20221211212014792.png" alt="image-20221211212014792" style="zoom:50%;" />

Git 分支实际上是指向更改快照的指针。

> 比如，现在要给一个项目增加功能；
>
> 就可以新建一个分支，这个新分支开始与原来的主分支完全一样。那么就可以对这个分支进行各种操作。反正都不会影响到原来的主分支；
>
> Git 还允许随时切换到主分支，此时项目又会变成原来的样子；
>
> 当认为功能已经完善，再执行分支的合并操作，把新增的功能合并到主分支即可；
>
> 这样的话，不过分支写的多烂，执行各种提交。也完全不会影响到主分支；
>
> 相比直接在主分支开发，安全高效很多；

分支管理主要使用的命令是：

创建分支命令：

```bash
git branch (branchname)
```

切换分支命令:

```bash
git checkout (branchname)
```

当切换分支的时候，Git 会用该分支的最后提交的快照替换工作目录的内容， 所以多个分支不需要多个目录；

合并分支命令:

```bash
git merge 
```

可以多次合并到统一分支， 也可以选择在合并之后直接删除被并入的分支。

下面用一个例子过一遍分支的操作：



## 建立测试仓库

创建一个测试目录：

```bash
$ mkdir gitdemo
$ cd gitdemo/
$ git init
Initialized empty Git repository...
$ touch README
$ git add README
$ git commit -m '第一次版本提交'
[master (root-commit) 3b58100] 第一次版本提交
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 README
```



## 列出分支

列出分支基本命令：

```bash
git branch
```

没有参数时，`git branch`  会列出本地的分支。

```bash
$ git branch
* master
```

意思就是，现在有一个叫做 ==master== 的分支，并且该分支是当前分支（用 `*` 指出）。

执行 `git init` 的时候，默认情况下 Git 就会创建 ==master== 分支。



## 新建分支

如果要手动创建一个分支。执行 `git branch (branchname)` 即可：

```bash
$ git branch testing
$ git branch
* master
  testing
```

现在有了一个新分支 **testing**。

> 当以此方式在上次提交更新之后创建了新分支 testing，此时 testing 与 master 完全一致，并且可以看到，当前位于的是 master 分支；
>
> 如果之后对文件修改，然后提交等操作，不会对 testing 分支进行任何影响；
>
> 切换到了 **testing** 分支，Git 将还原工作目录到创建分支时候的样子



## 切换分支

用 `git checkout (branch)` 切换到指定的分支。

````bash
$ ls
README
$ echo 'test for branches' > test.txt
$ git add .
$ git commit -m 'add test.txt'
[master 3e92c19] add test.txt
 1 file changed, 1 insertion(+)
 create mode 100644 test.txt
$ ls
README        test.txt
$ git checkout testing
Switched to branch 'testing'
$ ls
README
````

切换到 ==testing== 分支的后，在 ==master== 分支添加的新文件 test.txt 被移除了。切换回 ==master== 分支的时候，它们又重新出现了。

```bash
$ git checkout master
Switched to branch 'master'
$ ls
README        test.txt
```

可以使用 `git checkout -b (branchname)` 命令来创建新分支并立即切换到该分支下，从而在该分支中操作。

```bash
$ git checkout -b newtest
Switched to a new branch 'newtest'
$ git rm test.txt 
rm 'test.txt'
$ ls
README
$ touch runoob.php
$ git add .
$ git commit -am 'removed test.txt、add runoob.php'
[newtest c1501a2] removed test.txt、add runoob.php
 2 files changed, 1 deletion(-)
 create mode 100644 runoob.php
 delete mode 100644 test.txt
$ ls
README        runoob.php
$ git checkout master
Switched to branch 'master'
$ ls
README        test.txt
```

创建了一个分支，在该分支上移除了一些文件 test.txt，并添加了 runoob.php 文件，然后切换回主分支，删除的 test.txt 文件又回来了，且新增加的 runoob.php 不存在主分支中。

使用分支将工作切分开来，从而能够在不同开发环境中做事，并来回切换。



## 删除分支

删除分支命令：

```bash
git branch -d (branchname)
```

例如要删除 testing 分支：

```bash
$ git branch
* master
  testing
$ git branch -d testing
Deleted branch testing (was 85fc7e7).
$ git branch
* master
```



## 分支合并

一旦某分支有了独立内容，终究会希望将它合并回到主分支。 

可以使用以下命令将任何分支合并到当前分支中去：

````bash
git merge (branchname)
````

意思是把 branchname 分支的内容合并到当前所在的分支；

例如这样：

````bash
$ git branch
* master
  newtest
$ ls
README        test.txt
$ git merge newtest
Updating 3e92c19..c1501a2
Fast-forward
 runoob.php | 0
 test.txt   | 1 -
 2 files changed, 1 deletion(-)
 create mode 100644 runoob.php
 delete mode 100644 test.txt
$ ls
README        runoob.php
````

以上实例将 newtest 分支合并到主分支去，test.txt 文件被删除。

合并完后就可以删除分支:

````bash
$ git branch -d newtest
Deleted branch newtest (was c1501a2).
````

删除后， 就只剩下 master 分支了：

```bash
$ git branch
* master
```



## 合并冲突

合并并不仅仅是简单的文件添加、移除的操作，Git 也会合并修改。

```bash
$ git branch
* master
$ cat runoob.php
```

首先，创建一个叫做 change_site 的分支，切换过去，将 runoob.php 内容改为:

```bash
<?php
echo 'runoob';
?>
```

执行操作，创建 change_site 分支：

```bash
$ git checkout -b change_site
Switched to a new branch 'change_site'
$ vim runoob.php
$ head -3 runoob.php
<?php
echo 'runoob';
?>
$ git commit -am 'changed the runoob.php'
[change_site 7774248] changed the runoob.php
 1 file changed, 3 insertions(+)
```

将修改的内容提交到 change_site 分支中。 现在，假如切换回 master 分支，可以看内容恢复到修改前的(空文件，没有代码)，此时修改主分支的 runoob.php 文件。

````bash
$ git checkout master
Switched to branch 'master'
$ cat runoob.php
$ vim runoob.php    # 修改内容如下
$ cat runoob.php
<?php
echo 1;
?>
$ git diff
diff --git a/runoob.php b/runoob.php
index e69de29..ac60739 100644
--- a/runoob.php
+++ b/runoob.php
@@ -0,0 +1,3 @@
+<?php
+echo 1;
+?>
$ git commit -am '修改代码'
[master c68142b] 修改代码
 1 file changed, 3 insertions(+)
````

```bash
$ git checkout master
Switched to branch 'master'
$ cat runoob.php
$ vim runoob.php    # 修改内容如下
$ cat runoob.php
<?php
echo 1;
?>
$ git diff
diff --git a/runoob.php b/runoob.php
index e69de29..ac60739 100644
--- a/runoob.php
+++ b/runoob.php
@@ -0,0 +1,3 @@
+<?php
+echo 1;
+?>
$ git commit -am '修改代码'
[master c68142b] 修改代码
 1 file changed, 3 insertions(+)
```

现在这些改变已经记录到 master 分支了。接下来将 "change_site" 分支合并过来。

```bash
$ git merge change_site
Auto-merging runoob.php
CONFLICT (content): Merge conflict in runoob.php
Automatic merge failed; fix conflicts and then commit the result.

$ cat runoob.php     # 打开文件，看到冲突内容
<?php
<<<<<<< HEAD
echo 1;
=======
echo 'runoob';
>>>>>>> change_site
?>
```

将前一个分支合并到 master 分支，一个合并冲突就出现了，接下来需要手动去修改它。

```bash
$ vim runoob.php 
$ cat runoob.php
<?php
echo 1;
echo 'runoob';
?>
$ git diff
diff --cc runoob.php
index ac60739,b63d7d7..0000000
--- a/runoob.php
+++ b/runoob.php
@@@ -1,3 -1,3 +1,4 @@@
  <?php
 +echo 1;
+ echo 'runoob';
  ?>
```

在 Git 中，我们可以用 git add 要告诉 Git 文件冲突已经解决

```bash
$ git status -s
UU runoob.php
$ git add runoob.php
$ git status -s
M  runoob.php
$ git commit
[master 88afe0e] Merge branch 'change_site'
```

现在成功解决了合并中的冲突，并提交了结果。

> 冲突的原因主要是：
>
> master 分支与 change_site 分支中，runoob.php 这个文件的某些行内容不一样，Git 不知道合并后是要 master 分支的还是 change_site 分支的内容；
>
> 而如果 master 分支中文件时空的，把 change_site 中的文件内容合并来，肯定就没有冲突，因为很明显只有 change_site 分支有内容；


