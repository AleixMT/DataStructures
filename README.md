<a id="readme-top"></a>

<!-- PROJECT SHIELDS -->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![GPLv3 License][license-shield]][license-url]

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <h3 align="center">DataStructures</h3>

  <p align="center">
    A personal collection of classic data-structure implementations in C, Java and Python.
    <br />
    <a href="https://github.com/AleixMT/DataStructures"><strong>Explore the repository »</strong></a>
    <br />
    <br />
    <a href="https://github.com/AleixMT/DataStructures/issues">Report Bug</a>
    ·
    <a href="https://github.com/AleixMT/DataStructures/issues">Request Feature</a>
  </p>
</div>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
        <li><a href="#whats-inside">What's Inside</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## About The Project

`DataStructures` gathers hand-written implementations of the classic abstract data types —
lists, stacks, queues, hash tables, skip lists, graphs, heaps and trees — across three
languages. It started as the coursework for the *Estructura de Dades* (Data Structures)
course of the Computer Science degree at [Universitat Rovira i Virgili (URV)][urv-url]
(2019–2020) and has been extended since with a small object-oriented list hierarchy in
Python and a double-ended queue in Java.

Each structure is implemented from first principles (no standard-library containers) and
ships with its own runnable test driver, so the repository doubles as a study reference for
how each structure is built and exercised.

The three language trees are independent; pick the one you want and build only that.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Built With

* [![C][c-shield]][c-url] &nbsp; C (C99, built with `gcc`)
* [![Java][java-shield]][java-url] &nbsp; Java (IntelliJ project, Java 8+)
* [![Python][python-shield]][python-url] &nbsp; Python 3
* [![GNU Make][make-shield]][make-url] &nbsp; GNU Make (one `makefile` per C module)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### What's Inside

```
C/        classic structures in C, each folder with its own makefile + test driver
java/     IntelliJ project with three sub-projects
python/   small object-oriented List / LinkedList hierarchy
```

**C/**

| Module              | Structure                                             | Extras / driver                                             |
| ------------------- | --------------------------------------------------- | -------------------------------------------------------- |
| `ArrayList/`        | Dynamic array list                                    | Sorting & search-cost exercise (`ArrayListTest.c`)         |
| `Stack/`            | Generic stack (`pila`) and a real-valued stack       | Reverse-Polish-notation calculator (`rpn.c`, `rpn_reals.c`) |
| `Queue/`            | Stacks and queues (`pilas`, `colas`)                 | `main.c` demo                                              |
| `CircularQueue/`    | Circular queue (`cua`) built on top of the stack     | Pascal-triangle generator (`trianglePascal.c`)             |
| `DoubleLinkedList/` | Doubly linked list                                    | *Student Manager* interactive CLI that persists to a file  |
| `HashTable/`        | Hash table with chaining (`thash`)                    | Driver that loads keys from `datos_hash.txt`               |
| `SkipList/`         | Probabilistic skip list                               | Randomised insert / search / delete test                   |
| `includes/`         | Shared helpers: `commonlib`, `random`, `ErrorCodes.h` | —                                                          |

**java/**

| Sub-project    | Contents                                                                                       |
| -------------- | ------------------------------------------------------------------------------------------- |
| `DoubleQueue/` | Double-ended queue with a static (array) and a dynamic (linked) implementation; `Main` uses it for palindrome checking |
| `Graph_Heap/`  | Generic graph + binary heap; `Main` loads Pajek `.net` networks from `data/` (airports, US power grid, world-trade web, URV e-mail) |
| `Huffman/`     | Generic list ADT + iterator and a Huffman tree / coder                                        |

**python/**

* `List` (abstract base class) with `Array` / `ArrayImpl`, `ArrayList` and `LinkedList` (`Node`) implementations, plus a `main.py` demo.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- GETTING STARTED -->
## Getting Started

### Prerequisites

You only need the toolchain for the language you want to run:

* **C** — a C compiler and GNU Make
  ```sh
  sudo apt install build-essential
  ```
* **Java** — a JDK (11+). The sub-projects are IntelliJ IDEA modules with no build file, so
  opening `java/` in IntelliJ is the smoothest path; `javac` on each `src/` tree also works.
* **Python** — Python 3 (standard library only)
  ```sh
  python3 --version
  ```

### Installation

```sh
git clone https://github.com/AleixMT/DataStructures
cd DataStructures
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- USAGE -->
## Usage

### C

Every module has its own `makefile`. From inside a module folder:

```sh
cd C/Stack
make            # build the test / demo binaries
./test          # run the stack test driver
```

Notes:

* `make run` (where defined) builds and then runs the module's main binary.
* `C/CircularQueue` and `C/DoubleLinkedList` reference sources under `C/Stack` and
  `C/includes`, so keep the tree intact.
* `C/Stack/rpn` reads its expression from `input3.txt` in the current directory — run it
  from inside `C/Stack/`.
* Test-driver output is currently in Catalan / Spanish.

### Java

Open `java/` (or an individual sub-project) in IntelliJ IDEA and run the `Main` class of the
sub-project you want. `Graph_Heap` expects `java/Graph_Heap` as the working directory so it
can find `data/*.net`.

### Python

```sh
cd python
python3 main.py
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- ROADMAP -->
## Roadmap

- [ ] Fix `C/ArrayList` include path (`../_includes/` → `../includes/`)
- [ ] Fix the conflicting `pila` declaration in `C/Queue/pilas.c`
- [ ] Modernise `C/HashTable/main.c` for current compilers (`#include <string.h>`, `getline` buffer type)
- [ ] Remove the committed `C/HashTable/main` binary and add a top-level `make` that builds every module
- [ ] Add a real build file (Maven or Gradle) for the Java sub-projects
- [ ] Translate the C test-driver output to English and unify the drivers
- [ ] Grow the Python side to cover stacks, queues, hash tables and trees like the C and Java trees

See the [open issues](https://github.com/AleixMT/DataStructures/issues) for the current list.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open-source community such an amazing place to learn and
create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- LICENSE -->
## License

Distributed under the GNU General Public License v3.0. See [`LICENSE`](LICENSE) for more
information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTACT -->
## Contact

Aleix Mariné-Tena — [aleix.marine.tena@gmail.com](mailto:aleix.marine.tena@gmail.com) —
[LinkedIn](https://www.linkedin.com/in/aleixmt/)

Project Link: [https://github.com/AleixMT/DataStructures](https://github.com/AleixMT/DataStructures)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* The *Estructura de Dades* course and teaching staff at [Universitat Rovira i Virgili][urv-url]
* Classmates who collaborated on some of the modules
* [Best-README-Template](https://github.com/othneildrew/Best-README-Template)
* [Img Shields](https://shields.io)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->
[contributors-shield]: https://img.shields.io/github/contributors/AleixMT/DataStructures.svg?style=for-the-badge
[contributors-url]: https://github.com/AleixMT/DataStructures/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/AleixMT/DataStructures.svg?style=for-the-badge
[forks-url]: https://github.com/AleixMT/DataStructures/network/members
[stars-shield]: https://img.shields.io/github/stars/AleixMT/DataStructures.svg?style=for-the-badge
[stars-url]: https://github.com/AleixMT/DataStructures/stargazers
[issues-shield]: https://img.shields.io/github/issues/AleixMT/DataStructures.svg?style=for-the-badge
[issues-url]: https://github.com/AleixMT/DataStructures/issues
[license-shield]: https://img.shields.io/github/license/AleixMT/DataStructures.svg?style=for-the-badge
[license-url]: https://github.com/AleixMT/DataStructures/blob/master/LICENSE
[urv-url]: https://www.urv.cat/
[c-shield]: https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white
[c-url]: https://en.wikipedia.org/wiki/C_(programming_language)
[java-shield]: https://img.shields.io/badge/Java-ED8B00?style=for-the-badge&logo=openjdk&logoColor=white
[java-url]: https://www.java.com
[python-shield]: https://img.shields.io/badge/Python-3670A0?style=for-the-badge&logo=python&logoColor=ffdd54
[python-url]: https://www.python.org
[make-shield]: https://img.shields.io/badge/GNU%20Make-A42E2B?style=for-the-badge&logo=gnu&logoColor=white
[make-url]: https://www.gnu.org/software/make/
