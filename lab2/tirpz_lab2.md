## Національний технічний університет України<br>“Київський політехнічний інститут ім. Ігоря Сікорського”

## Факультет прикладної математики<br>Кафедра системного програмування і спеціалізованих комп’ютерних систем


# Лабораторна робота №2<br>"Розширена робота з git"

## КВ-11 Коротич Олександр

## Хід виконання роботи:

## 1. Зклонувати будь-який невеликий проєкт open-source з github:

### 1. Зклонувати двічі: повний репозиторій, а також частковий, що міститиме лише один коміт однієї гілки за вашим вибором

```
$ git clone https://gitlab.com/CalcProgrammer1/OpenRGB.git
Cloning into 'OpenRGB'...
remote: Enumerating objects: 29073, done.
remote: Counting objects: 100% (522/522), done.
remote: Compressing objects: 100% (118/118), done.
remote: Total 29073 (delta 408), reused 493 (delta 394), pack-reused 28551
Receiving objects: 100% (29073/29073), 35.85 MiB | 35.20 MiB/s, done.
Resolving deltas: 100% (21601/21601), done.
Updating files: 100% (2835/2835), done.
```
```
$ git clone https://gitlab.com/CalcProgrammer1/OpenRGB --depth=2 --single-branch --branch=fan_controller openrgb-shallow
Cloning into 'openrgb-shallow'...
warning: redirecting to https://gitlab.com/CalcProgrammer1/OpenRGB.git/
remote: Enumerating objects: 3101, done.
remote: Counting objects: 100% (3101/3101), done.
remote: Compressing objects: 100% (2416/2416), done.
remote: Total 3101 (delta 861), reused 2389 (delta 632), pack-reused 0
Receiving objects: 100% (3101/3101), 28.82 MiB | 38.72 MiB/s, done.
Resolving deltas: 100% (861/861), done.
Updating files: 100% (2809/2809), done.
```
### 2. Показати різницю в розмірі баз даних двох клонів:
```
$ dir /s "OpenRGB"
Total Files Listed:
   2861 File(s)     99,621,069 bytes
```
```
$ dir /s "openrgb-shallow"
Total Files Listed:
   2834 File(s)     91,206,824 bytes
```


## 2. Зробити не менше трьох локальних комітів:

### 1. Продемонструвати різні способи додавання файлів до індексу:

```
$ git add 1.txt
$ git add .
$ git add *.txt
$ git add -A
```

### 2. Продемонструвати різні способи вказання повідомлення коміту:

```
$ git commit -m "add 1.txt"
[master 4e86f269] add 1.txt
 1 file changed, 1 insertions(+)
 create mode 100644 1.txt
```
```
$ git commit
[master a2db4dde] add 2.
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 2.txt
```

## 3. Продемонструвати уміння вносити зміни до останнього коміту за допомогою опції --amend:

```
$ git commit --amend -m "amended add 3.txt"
[master ba1f8bb6] amended add 3.txt
 Date: Wed Oct 4 20:12:58 2023 +0300
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 3.txt
```

## 4. Продемонструвати уміння об'єднати кілька останніх комітів в один за допомогою git reset:

```
$ git status
On branch master
Your branch is ahead of 'origin/master' by 3 commits.
  (use "git push" to publish your local commits)

nothing to commit, working tree clean

$ git reset HEAD~2

$ git status
On branch master
Your branch is ahead of 'origin/master' by 1 commit.
  (use "git push" to publish your local commits)

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        2.txt
        3.txt

nothing added to commit but untracked files present (use "git add" to track)

$ git add .

$ git commit -m "add 2.txt 3.txt"
[master 2274d42d] add 2.txt 3.txt
 2 files changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 2.txt
 create mode 100644 3.txt
```

## 5. Видалити файл(и) одним способом на вибір:

```
$ del Colors.h

$ git status
On branch master
Your branch is behind 'origin/master' by 1 commit, and can be fast-forwarded.
  (use "git pull" to update your local branch)

Changes not staged for commit:
  (use "git add/rm <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        deleted:    Colors.h

no changes added to commit (use "git add" and/or "git commit -a")

$ git add Colors.h

$ git status
On branch master
Your branch is behind 'origin/master' by 1 commit, and can be fast-forwarded.
  (use "git pull" to update your local branch)

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        deleted:    Colors.h
```

## 6. Перемістити файл(и) одним способом на вибір:

```
$ git mv Colors.h Stuff.h

$ git status
On branch master
Your branch is behind 'origin/master' by 1 commit, and can be fast-forwarded.
  (use "git pull" to update your local branch)

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        renamed:    Colors.h -> Stuff.h
```

## 7. Гілкування:

### 1. Створити три гілки, принаймні з одним унікальним комітом кожна:

```
$ git branch
* master

$ git status
On branch master
Your branch is up to date with 'origin/master'.

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        1.txt
        2.txt
        3.txt

nothing added to commit but untracked files present (use "git add" to track)

$ git branch branch-1

$ git checkout branch-1

$ git branch
* branch-1
  master

$ git status
On branch branch-1
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        1.txt
        2.txt
        3.txt
        4.txt

nothing added to commit but untracked files present (use "git add" to track)

$ git add 1.txt

$ git commit -m "add 1.txt"
[branch-1 99831283] add 1.txt
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 1.txt

$ git status
On branch branch-1
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        2.txt
        3.txt
        4.txt

nothing added to commit but untracked files present (use "git add" to track)

$ git branch branch-2

$ git git checkout branch-2

$ >git branch
  branch-1
* branch-2
  master

$ git status
On branch branch-2
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        2.txt
        3.txt
        4.txt

nothing added to commit but untracked files present (use "git add" to track)

$ git add 2.txt 3.txt

$ git commit -m "add 2.txt 3.txt"
[branch-2 982fac6c] add *.txt
 2 files changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 2.txt
 create mode 100644 3.txt

$ git status
On branch branch-2
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        4.txt

nothing added to commit but untracked files present (use "git add" to track)

$ git checkout master
Switched to branch 'master'
Your branch is up to date with 'origin/master'.

$ git status
On branch master
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        4.txt

nothing added to commit but untracked files present (use "git add" to track)

$ git branch branch-3

$ git checkout branch-3
Switched to branch 'branch-3'

$ git add 4.txt

$ git commit -m "add 4.txt"
[branch-3 b5e13814] add 4.txt
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 4.txt

$ git status
On branch branch-3
nothing to commit, working tree clean

$ git checkout master
Switched to branch 'master'
Your branch is up to date with 'origin/master'.
```

## 8. Продемонструвати уміння знайти в історії комітів набір комітів, в яких була зміна по конкретному шаблону в конкретному файлі:

```
$ git log -G "i2c-tools" README.md
commit 1c4c4bd010222e84a822284aff5d1420c2bc6f8f
Author: Flora Aubry <aethernali.live@gmail.com>
Date:   Thu Jun 8 08:42:41 2023 +0000

    Added more informations about i2c

$ git show 1c4c4bd010222e84a822284aff5d1420c2bc6f8f README.md
commit 1c4c4bd010222e84a822284aff5d1420c2bc6f8f
Author: Flora Aubry <aethernali.live@gmail.com>
Date:   Thu Jun 8 08:42:41 2023 +0000

    Added more informations about i2c

diff --git a/README.md b/README.md
index e7653f4a..b6fb9abc 100644
--- a/README.md
+++ b/README.md
@@ -140,8 +140,12 @@ There have been two instances of hardware damage in OpenRGB's development and we
   * If you are not trying to use OpenRGB to control RGB RAM or motherboard LEDs, you may skip this section.
   * ASUS and ASRock motherboards have their RGB controller on a secondary SMBus interface and requires a Linux kernel > 5.7 <sup>[commit](https://github.com/torvalds/linux/commit/f27237c174fd9653033330e4e532cd9d153ce824)</sup>
   * Allowing access to SMBus:
-    1. Load the i2c-dev module: `sudo modprobe i2c-dev`
-    2. Load the i2c driver for your chipset:
+    1. Install the `i2c-tools` package.
+    2. Load the i2c-dev module: `sudo modprobe i2c-dev`
+    3. Create the i2c group if it does not already exist: `sudo groupadd --system i2c`
+    4. Add yourself to the i2c group: `sudo usermod $USER -aG i2c`
+    5. If you want you can load the i2c-dev module at boot: `sudo touch /etc/modules-load.d/i2c.conf && sudo sh -c 'echo "i2c-dev" >> /etc/modules-load.d/i2c.conf'`
+    6. Load the i2c driver for your chipset:
     <details>
     <summary><h6>Intel</h6></summary>
```