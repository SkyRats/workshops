# Git: um Sistema de Controle de Versão Distribuido

## Por que controle de versão existe?

A programação antes da internet era muito diferente do que é hoje, porque era mais difícil acessar informação e compartilhar código, o que desacelerava a inovação. Mas um mundo conectado exigia novas formas de colaboração, e com elas novas ferramentas para colaborar.

Imagine que você é um programador da décade de 70 tentando, por exemplo, fazer um drone voar sozinho. Você teria que programar tudo absolutamente do zero - desde como os motores são controlados até rotinas de pouso e movimentação por exemplo, e tudo isso antes de pensar em fazer o seu drone se controlar autonomamente! Isso acontece porque você não tem acesso ao trabalho de outros programadores, já que a única forma de compartilhar código era copiando em um disquete e mandar para outras pessoas. E esse problema não existia só em robótica - desenvolver uma nova aplicação muitas vezes envolvia escrever também o sistema operacional para o computador.

O desenvolvimento da internet permitiu que arquivos fossem compartilhador mais facilmente, permitindo que várias pessaos trabalhassem remotamente em um mesmo projeto, até de diferntes países. Assim, não era preciso inventar a roda de novo toda vez, mas existia um outro problema: como lidar com equipes de programadores em lugares diferentes, modificando todos ao mesmo tempo os mesmos arquivos?

Daí vem a necessidade de sistemas de controle de versão (SCV) para vários usuários. Esses sistemas permitem que várias pessoas façam modificações, e depois encontra um jeito de juntar todas elas automaticamente. Eles também permitem muito mais, como voltar em versões passadas dos seus arquivos, de uma forma simples e integrada.

Ok, mas esse é o workshop de Git, que é só um SCV. Por que afinal a gente usa o Git? O que ele tem de especial?

---

- Files are indexed by their checksums
    - Makes it impossible to modify files in the history
- Operations are almost all local
    - Doesn't require a constant connection to the remote
- Git stores snapshots of files
    - Stores a version and pointers (references) to all files at the time of the commit
    - Other VCSs store modifications to files

## What is Git?

- Distributed Version Control System
    - Each user has the entire history of the repository in their local machines
    - Allows for offline work and makes "security copies" in case of any event with the main server

### How does Git work?

- The Three States of Git
    - Working directory (from now WD) → the files in your computer
    - Staging area (aka Index, from now SA) → the modifications to files that will be saved in your next commit
    - (Remote) Repository → the collection of all your past commits

### What makes Git unique?

- Files are indexed by their checksums
    - Makes it impossible to modify files in the history
- Operations are almost all local
    - Doesn't require a constant connection to the remote
- Git stores snapshots of files
    - Stores a version and pointers (references) to all files at the time of the commit
    - Other VCSs store modifications to files

## The Git Cycle

- Untracked
- Unmodified
- Modified
- Staged

## `.gitignore`

- Stops git from tracking certain files (ex. binaries, data bases, logs)
- Interesting options
    - * → select all file names
    - ! → reverse one of the rules set previously
    - /filename → only in the current directory
    - dirname/ → ignore all files, folders and subfolders of dirname
    - dirname/**/filename → ignore all files inside subdiretories
- Example

```bash
# Comments strat with #

# Ignore all .a files...
*.a
# ... but track lib.a
!lib.a
# Ignore TODO files in CW
/TODO
# Ignore build and sub folders/files
build/
# Ignore all .txt in docs, but not in its subfolders
doc/*.txt
# Ignore all .pdf in all sufolders of doc
doc/**/*.pdf
```

### Setting up a global `.gitignore`

- Create a file in your `$HOME` (by convention called `.gitignore_global`)
- Use that file with the usual `.gitignore`syntax
- Set up Git to use the global file

```bash
git config --global core.excludefile ~/.gitignore_global
```

## Branching

- Branches are collections of commit objects
    - Each object has metadata associated with the commit, a tree (mapping file modifications), blobs (describing file modifications), and pointers to the previous and next commits
- The current branch is pointed at by HEAD

### Merging

- If the history of the branches doesn't diverge (i.e. one branch has commits all older than the commits of the other branch), they can be fast-forwarded
- When histories diverge but there is no conflict, Git creates a merge commit that has two parents, one from each merged branch
- When the same parts of a file are edited in both branches, a conflict occurs
    - Example

        ```bash
        <<<<<<< HEAD
        this is some content to mess with
        content to append
        =======
        totally different content to merge later
        >>>>>>> new_branch
        ```

    - Conflicts need to be resolved manually by deleting the segment between `>>>>>>>` and `<<<<<<<`
    - You can either select one of the edits or create something entirely different as you wish
    - After resolving a conflict, add files and commit

## Revision Selection

- How can you select previous commits for visualisation?
- Branch names expand to references to their HEADs
- `~` to reference first parents
    - `~2` references grandparent
- `^` to reference other parents
    - `^2` references second parent (of a merge commit)

### `..` syntax

- Shows differences between references
- `<reference>..<reference to show differences>`
- Can be replaced with `<reference to show difference> —not <reference>`

### `...` syntax

- Shows commits since last common point between references
- `<reference>...<second reference>`
- `—left-right` shows to which reference commit belongs

## Git Workflows

- Git also allows for collaboration between teams of developers
- There are some standard ways for collaboration
- There is no one-size-fits-all solution

### Centralised

- All developers push their commits to a single branch
- Conflicts are resolved by rebasing newer changes on top of older ondes
- Can slow down the team due to many conflict resolutions

### Feature Branch

- Each branch for the repository serves a distinct and very specific goal (e.g. working on a bug fix or on a new feature)
- The developer makes sure their master is up to date with the remote master and updates and fixes conflicts locally if necessary
- When the changes are ready, a pull request is opened to review the changes
- The changes are then incorporated into the master branch

### Gitflow

- More rigid structure for Feature Branch
- There are some "canonical" branches
    - `master` → where final, ready-to-use code is
    - `develop` or `devel` → where changes are merged between releases
- During development, each new feature gets its own `feature` branch as well, which is merged into `develop` when ready
- When a release comes up, a new branch, `release`, is created
    - No new features are added to `release`, only bug fixes and documentation generation
    - The release feature is merged into `master`, and then back into `develop` with new documentation and bug fixes
- Whenever necessary, a new `hotfix` branch can be created to fix critical bug found in the `master` branch
    - After merging `hotfix` into `master`, a new release is generated
    - `hotfix` is also merged into develop

---

  

[Commands](https://www.notion.so/2e7fa76e5a7a4fcf964fb97d82e81650)