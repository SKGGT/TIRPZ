## Національний технічний університет України<br>“Київський політехнічний інститут ім. Ігоря Сікорського”

## Факультет прикладної математики<br>Кафедра системного програмування і спеціалізованих комп’ютерних систем


# Лабораторна робота №2<br>"Розширена робота з git"

## КВ-11 Коротич Олександр

## Хід виконання роботи:

## 1. Зклонувати репозиторій для ЛР2 використавши локальний репозиторій від ЛР1 в якості "віддаленого".

```
$ git clone file:///C:\Users\sasha\Documents\GitHub\TIRPZ\lab1\yt-dlp
Cloning into 'yt-dlp'...
remote: Enumerating objects: 119310, done.
remote: Counting objects: 100% (119310/119310), done.
remote: Compressing objects: 100% (25551/25551), done.
Receiving objects: 100% (119310/119310), 44.71 MiB | 37.77 MiB/s, done.
remote: Total 119310 (delta 93100), reused 119302 (delta 93096), pack-reused 0
Resolving deltas: 100% (93100/93100), done.
```
```
$ git branch -a
* master
  remotes/origin/HEAD -> origin/master
  remotes/origin/lab1
  remotes/origin/master
```
## 2. Робота з ремоутами:

### 1. Додати новий ремоут використавши URI на інтернет-джерело вашого репозиторію:

```
$ git remote -v
origin  file:///C:\Users\sasha\Documents\GitHub\TIRPZ\lab1\yt-dlp (fetch)
origin  file:///C:\Users\sasha\Documents\GitHub\TIRPZ\lab1\yt-dlp (push)
```
```
$ git remote add upstream https://github.com/yt-dlp/yt-dlp.git
```
```
$ git remote -v
origin  file:///C:\Users\sasha\Documents\GitHub\TIRPZ\lab1\yt-dlp (fetch)
origin  file:///C:\Users\sasha\Documents\GitHub\TIRPZ\lab1\yt-dlp (push)
upstream        https://github.com/yt-dlp/yt-dlp.git (fetch)
upstream        https://github.com/yt-dlp/yt-dlp.git (push)
```

### 2. Показати список віддалених гілок, так щоби було видно гілки з різних ремоутів:

```
$ git fetch upstream
remote: Enumerating objects: 2, done.
remote: Total 2 (delta 0), reused 0 (delta 0), pack-reused 2
Unpacking objects: 100% (2/2), 139 bytes | 9.00 KiB/s, done.
From https://github.com/yt-dlp/yt-dlp
 * [new branch]          gh-pages   -> upstream/gh-pages
 * [new branch]          master     -> upstream/master
 * [new branch]          release    -> upstream/release
```
```
$ git branch -a
* master
  remotes/origin/HEAD -> origin/master
  remotes/origin/lab1
  remotes/origin/master
  remotes/upstream/gh-pages
  remotes/upstream/master
  remotes/upstream/release
```

### 3. Створити нову гілку lab2-branch, додати в нього кілька комітів.

```
$ git branch
* lab2-branch
  master
```
```
$ git status
On branch lab2-branch
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        11.txt
        22.txt
        33.txt

nothing added to commit but untracked files present (use "git add" to track)
```
```
$ git add 11.txt
```
```
$ git commit -m "11.txt"
[lab2-branch 82622983e] 11.txt
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 11.txt
```
Повторили цю процидуру й для 22.txt та 33.txt для 3 окремих комітів на lab2-branch

### 4. Пушнути гілку lab2-branch на ремоут, створений з ЛР1 без зв'язування локальної гілки з віддаленою.

```
$ git push origin lab2-branch
Enumerating objects: 7, done.
Counting objects: 100% (7/7), done.
Delta compression using up to 20 threads
Compressing objects: 100% (6/6), done.
Writing objects: 100% (6/6), 592 bytes | 592.00 KiB/s, done.
Total 6 (delta 3), reused 0 (delta 0), pack-reused 0
To file:///C:\Users\sasha\Documents\GitHub\TIRPZ\lab1\yt-dlp
 * [new branch]          lab2-branch -> lab2-branch
```

### 5. Додати до гілки ще коміт.

```
$ git commit -m "44.txt and 55.txt"
[lab2-branch 86a73b7a8] 44.txt and 55.txt
 2 files changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 44.txt
 create mode 100644 55.txt
```

### 6. Пушнути зміни гілки на ремоут, створений з ЛР1, цього разу зв'язавши гілки.

```
$ git push -u origin lab2-branch
Enumerating objects: 3, done.
Counting objects: 100% (3/3), done.
Delta compression using up to 20 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (2/2), 243 bytes | 243.00 KiB/s, done.
Total 2 (delta 1), reused 0 (delta 0), pack-reused 0
To file:///C:\Users\sasha\Documents\GitHub\TIRPZ\lab1\yt-dlp
   4cd473d31..86a73b7a8  lab2-branch -> lab2-branch
branch 'lab2-branch' set up to track 'origin/lab2-branch'.
```

### 7. Додати до гілки ще коміт.

```
$ git commit -m "66.txt"
[lab2-branch b4f837fb9] 66.txt
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 66.txt
```

### 8. Переконатися в тому, що після зв'язування гілок тепер можна пушити просто через git push.

```
$ git push
Enumerating objects: 3, done.
Counting objects: 100% (3/3), done.
Delta compression using up to 20 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (2/2), 228 bytes | 228.00 KiB/s, done.
Total 2 (delta 1), reused 0 (delta 0), pack-reused 0
To file:///C:\Users\sasha\Documents\GitHub\TIRPZ\lab1\yt-dlp
   86a73b7a8..b4f837fb9  lab2-branch -> lab2-branch
```

### 9. Перевірити в репозиторії ЛР1, що після пушу тут з'явилася нова локальна гілка (яку ми власне пушнули).

```
$ git branch -a
  lab1
  lab2-branch
* master
  remotes/origin/HEAD -> origin/master
  remotes/origin/gh-pages
  remotes/origin/master
  remotes/origin/release
```

## 3. Змерджити гілку, що була створена при виконанні ЛР1, в поточну гілку lab2-branch:

```
$ git merge origin/lab1
Merge made by the 'ort' strategy.
 3.txt | 0
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 3.txt
```
```
$ git log --pretty=oneline --graph
*   368ae9634a788b02642a834c3f1c4a509df5f91a (HEAD -> lab2-branch) Merge remote-tracking branch 'origin/lab1' into lab2-branch
|\
| * d3e30d9a0efb3141ef5f2ebf5199f946fa8a538c (origin/lab1) 3.txt
* | b4f837fb9d2c51506df1aeac5aebc8395be0cfe5 (origin/lab2-branch) 66.txt
* | 86a73b7a852937e0093d0035af8621f1557794f9 44.txt and 55.txt
* | 4cd473d31e0e73b29f8cfe981712ffb85270e3d4 33.txt
* | a265cea4cff5833f088604c0290afcbb86bbe5cf 22.txt
* | 82622983ec8798c82854d77a15870fb2ef4cd1b8 11.txt
|/
* 2f7787cf443d880c9f83e781ff4165e1dd669370 (origin/master, origin/HEAD, master) 2.txt
* 6fc13141252b60d6e737cd72cd6fc11223014a82 1.txt
```
## 4. Перенесення комітів:

```
$ git cherry-pick a265cea4cff5833f088604c0290afcbb86bbe5cf
The previous cherry-pick is now empty, possibly due to conflict resolution.
If you wish to commit it anyway, use:

    git commit --allow-empty

Otherwise, please use 'git cherry-pick --skip'
On branch lab2-branch
Your branch is ahead of 'origin/lab2-branch' by 3 commits.
  (use "git push" to publish your local commits)

You are currently cherry-picking commit a265cea4c.
  (all conflicts fixed: run "git cherry-pick --continue")
  (use "git cherry-pick --skip" to skip this patch)
  (use "git cherry-pick --abort" to cancel the cherry-pick operation)

nothing to commit, working tree clean
```
```
$ git commit --allow-empty
[lab2-branch e0b267480] 22.txt
 Date: Wed Nov 15 17:45:53 2023 +0200
```

### 1. Створити ще одну гілку від master-a lab2-branch-2, додати в неї три коміти:

```
$ git checkout -b lab2-branch-2
Switched to branch 'lab2-branch-2'
```
```
$ git add 111.txt
```
```
$ git commit -m "111.txt"
[lab2-branch-2 fcb057d14] 111.txt
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 111.txt
```
Повторював процес ще 2 рази для 222.txt та 333.txt

### 2. Перенести з гілки lab2-branch-2 середній з трьох нових комітів в гілку lab2-branch:

```
$ git branch
* lab2-branch
  lab2-branch-2
  master
```
```
$ git log --pretty=oneline --graph -n 12 --branches
* e0b267480a307405e70cfd54137e123649b98ca6 (lab2-branch) 22.txt
*   368ae9634a788b02642a834c3f1c4a509df5f91a Merge remote-tracking branch 'origin/lab1' into lab2-branch
|\
| * d3e30d9a0efb3141ef5f2ebf5199f946fa8a538c (origin/lab1) 3.txt
* | b4f837fb9d2c51506df1aeac5aebc8395be0cfe5 (origin/lab2-branch) 66.txt
* | 86a73b7a852937e0093d0035af8621f1557794f9 44.txt and 55.txt
* | 4cd473d31e0e73b29f8cfe981712ffb85270e3d4 33.txt
* | a265cea4cff5833f088604c0290afcbb86bbe5cf 22.txt
* | 82622983ec8798c82854d77a15870fb2ef4cd1b8 11.txt
|/
| * 4373399449534fd152f6d75f6b14e0b98fb7b4e5 (HEAD -> lab2-branch-2) 333.txt
| * 9813d4b54a468d5cb41b1817514377d8fbb6ed83 222.txt
| * fcb057d143e9d5aaa2da81b88c261d7167a1cafd 111.txt
|/
* 2f7787cf443d880c9f83e781ff4165e1dd669370 (origin/master, origin/HEAD, master) 2.txt
```
```
$ git cherry-pick 9813d4b54a468d5cb41b1817514377d8fbb6ed83
[lab2-branch fc6502aa5] 222.txt
 Date: Wed Nov 15 18:00:41 2023 +0200
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 222.txt
```

## 5. Визначити останнього спільного предка між двома будь-якими гілками:

```
$ git merge-base origin/lab2-branch origin/lab1
2f7787cf443d880c9f83e781ff4165e1dd669370
```

## 6. Робота з ничкою:

### 1. Зробити трохи unstaged змін.

```
$ git checkout master
Switched to branch 'master'
Your branch is up to date with 'origin/master'.
```
```
$ git status
On branch master
Your branch is up to date with 'origin/master'.

Changes not staged for commit:
  (use "git add/rm <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        deleted:    1.txt
        deleted:    2.txt

no changes added to commit (use "git add" and/or "git commit -a")
```

### 2. Зберегти до нички.

```
$ git stash
Saved working directory and index state WIP on master: 2f7787cf4 2.txt
```
```
$ git status
On branch master
Your branch is up to date with 'origin/master'.

nothing to commit, working tree clean
```

### 3. Зробити ще трохи unstaged змін.

```
$ git status
On branch master
Your branch is up to date with 'origin/master'.

Changes not staged for commit:
  (use "git add/rm <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        deleted:    README.md

no changes added to commit (use "git add" and/or "git commit -a")
```

### 4. Зберегти до нички.

```
$ git stash
Saved working directory and index state WIP on master: 2f7787cf4 2.txt
```

### 5. Дістати з нички перші збережені зміни, ті що збереглися на кроці (6.2).

```
$ git stash list
stash@{0}: WIP on master: 2f7787cf4 2.txt
stash@{1}: WIP on master: 2f7787cf4 2.txt
```
```
$ git stash apply 1
On branch master
Your branch is up to date with 'origin/master'.

Changes not staged for commit:
  (use "git add/rm <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        deleted:    1.txt
        deleted:    2.txt

no changes added to commit (use "git add" and/or "git commit -a")
```
```
$ git stash list
stash@{0}: WIP on master: 2f7787cf4 2.txt
stash@{1}: WIP on master: 2f7787cf4 2.txt
```

## 7. Робота з файлом .gitignore.

### 1. Створити кілька файлів з якимось унікальним розширенням.

```
$ git status
On branch master
Your branch is up to date with 'origin/master'.

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        info.csv
        output1.data
        output2.data
        secret.sha256

nothing added to commit but untracked files present (use "git add" to track)
```

### 2. Додати шаблон для цих файлів в ігнор.

```
*.csv
*.data
*.sha256
```

### 3. Перевірити статус -- файли повинні зникнути.

```
$ git status
On branch master
Your branch is up to date with 'origin/master'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   .gitignore

no changes added to commit (use "git add" and/or "git commit -a")
```

### 4. Перевірити статус включно з ігнором.

```
$ git status --ignored
On branch master
Your branch is up to date with 'origin/master'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   .gitignore

Ignored files:
  (use "git add -f <file>..." to include in what will be committed)
        info.csv
        output1.data
        output2.data
        secret.sha256

no changes added to commit (use "git add" and/or "git commit -a")
```

### 5. Почистити всі untracked файли з репозиторію, включно з ігнорованими.

```
$ git clean -fdx
Removing info.csv
Removing output1.data
Removing output2.data
Removing secret.sha256
```
```
$ git status --ignored
On branch master
Your branch is up to date with 'origin/master'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   .gitignore

no changes added to commit (use "git add" and/or "git commit -a")
```

## 8. Робота з reflog.

### 1. Переглянути лог станів гілок.

```
$ git reflog
d0a7e6d2d (HEAD -> lab2-branch) HEAD@{0}: commit: gitignore
fc6502aa5 HEAD@{1}: checkout: moving from master to lab2-branch
2f7787cf4 (origin/master, origin/HEAD, master) HEAD@{2}: reset: moving to HEAD
2f7787cf4 (origin/master, origin/HEAD, master) HEAD@{3}: reset: moving to HEAD
2f7787cf4 (origin/master, origin/HEAD, master) HEAD@{4}: reset: moving to HEAD
2f7787cf4 (origin/master, origin/HEAD, master) HEAD@{5}: checkout: moving from lab2-branch to master
fc6502aa5 HEAD@{6}: cherry-pick: 222.txt
e0b267480 HEAD@{7}: checkout: moving from lab2-branch-2 to lab2-branch
437339944 (lab2-branch-2) HEAD@{8}: reset: moving to lab2-branch-2~1
55c3ba119 HEAD@{9}: reset: moving to lab2-branch-2
55c3ba119 HEAD@{10}: commit (cherry-pick): 222.txt
```

### 2. Створити нову гілку на будь-який стан зі списку та переключитися на цю гілку.

```
$ git branch lab2-reflog 55c3ba119
```
```
$ git checkout lab2-reflog
Switched to branch 'lab2-reflog'
```
```
$ git log --pretty=oneline --graph -n 15
* 55c3ba119d26d7c95b4d40cf815870995b961425 (HEAD -> lab2-reflog) 222.txt
* 4373399449534fd152f6d75f6b14e0b98fb7b4e5 (lab2-branch-2) 333.txt
* 9813d4b54a468d5cb41b1817514377d8fbb6ed83 222.txt
* fcb057d143e9d5aaa2da81b88c261d7167a1cafd 111.txt
* 2f7787cf443d880c9f83e781ff4165e1dd669370 (origin/master, origin/HEAD, master) 2.txt
* 6fc13141252b60d6e737cd72cd6fc11223014a82 1.txt
```