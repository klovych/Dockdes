# Dockdes

Dockdes is a terminal-based application written in C that helps users generate Google search queries with advanced filters, also known as "Google Dorks". This tool supports both **English** and **Russian** languages, allowing users to customize their search queries easily.

---

## 🖼️ Features

- **Google Dorking Filters**:
  - Search within a specific site (`site:`)
  - Search for specific file types (`filetype:`)
  - Search for keywords in URLs (`inurl:`)
  - Search for keywords in page titles (`intitle:`)
  - Search for specific text on a page (`allintext:`)
  - Search for individual words on a page (`intext:`)
  - View cached versions of a site (`cache:`)

- **Multi-language Support**:
  - English
  - Russian

- **User-friendly Interface**:
  - Simple menu-driven navigation.
  - Clean and intuitive ASCII art banner.

- **Dynamic URL Generation**:
  - Automatically builds Google search URLs based on selected filters.

---


## 🔧 How to Build and Run

### Prerequisites
- GCC or any C compiler installed on your system.
- Basic knowledge of using a terminal.

### Steps to Compile and Run:
1. Clone this repository:
   ```bash
   git clone https://github.com/klovych/Dockdes.git
   cd dockdes
2. Compile the program:
  ```bash
   gcc dockdes.c -o dockdes
  ```
3. Run this program:
   ```bash
   ./dockdes


🌐 How to Use
Select a language: Choose between English or Russian at startup.
Select filters: Pick one or more Google Dorking filters from the menu.
Enter filter values: Provide inputs for the selected filters (e.g., site domain, file type, keywords).
Generate URL: The tool will generate a Google search URL based on your inputs.
Open in Browser: Copy the generated URL and paste it into your browser to execute the search.
