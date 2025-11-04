#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Error: No project name or option provided.\n";
        std::cout << "Usage: " << argv[0] << " <project_name>\n";
        return 1;
    }
    if (std::string(argv[1]) == "--help")
    {
        std::cout << "Usage: " << argv[0] << " <project_name>\n";
        std::cout << "Creates a basic Python project structure.\n";
        return 0;
    }
    else if (std::string(argv[1]) == "--version")
    {
        std::cout << "Project Structure Creator v1.0.0\n";
        return 0;
    }
    else if (argc == 3 && std::string(argv[1]) == "class")
    {
        std::string upName;
        for (size_t i = 0; i < std::string(argv[2]).size(); i++)
        {
            upName += toupper(argv[2][i]);
        }
        std::ofstream h_file("includes/" + std::string(argv[2]) + ".h");
        if (!h_file.is_open())
        {
            std::cout << "error create .h file\n";
            return 1;
        }
        h_file << "#ifndef " + upName + "_H\n"
               << "#define " + upName + "_H\n\n"
               << "#include <iostream>\n"
               << "\nclass " + std::string(argv[2]) + "\n{};\n\n"
               << "#endif " + std::string("// ") + upName + "_H\n";
        h_file.close();
        std::ofstream cpp_file("src/" + std::string(argv[2]) + ".cpp");
        if (!cpp_file.is_open())
        {
            std::cout << "error create .cpp file\n";
            return 1;
        }
        cpp_file << "#include <iostream>";
        cpp_file.close();
        std::cout << "class '" + std::string(argv[2]) + "' create\n";
    }
    else
    {
        if (argc < 3)
        {
            std::cout << "Error: No project type specified. Use 'python' or 'cpp'.\n";
            return 1;
        }
        if (std::string(argv[2]) == "python")
        {
            std::filesystem::create_directories(argv[1]);
            std::filesystem::create_directories(std::string(argv[1]) + "/src");
            std::filesystem::create_directories(std::string(argv[1]) + "/tests");
            std::filesystem::create_directories(std::string(argv[1]) + "/docs");
            std::ofstream main_file(std::string(argv[1]) + "/src/main.py");
            main_file.close();
            std::ofstream readme_file(std::string(argv[1]) + "/README.md");
            readme_file.close();
            std::ofstream requirements_file(std::string(argv[1]) + "/requirements.txt");
            requirements_file.close();
            std::ofstream setup_file(std::string(argv[1]) + "/setup.py");
            setup_file << "from setuptools import setup, find_packages\n\n"
                       << "setup(\n"
                       << "    name='" << argv[1] << "',\n"
                       << "    version='0.1.0',\n"
                       << "    packages=find_packages(),\n"
                       << "    install_requires=[],\n"
                       << ")\n";
            setup_file.close();
            std::cout << "Project structure for '" << argv[1] << "' created successfully.\n";
        }
        else if (std::string(argv[2]) == "c++")
        {
            if (argc == 3)
            {
                std::filesystem::create_directories(argv[1]);
                std::filesystem::create_directories(std::string(argv[1]) + "/src");
                std::filesystem::create_directories(std::string(argv[1]) + "/includes");
                std::filesystem::create_directories(std::string(argv[1]) + "/build");
                std::ofstream main_file(std::string(argv[1]) + "/src/main.cpp");
                main_file << "#include <iostream>\n\n"
                          << "int main() \n{\n"
                          << "    std::cout << \"Hello, World!\" << std::endl;\n"
                          << "    return 0;\n"
                          << "}\n";
                main_file.close();
                std::ofstream readme_file(std::string(argv[1]) + "/README.md");
                readme_file.close();
                std::ofstream makefile(std::string(argv[1]) + "/Makefile");
                makefile << "all:\n"
                         << "\tg++ -o build/main src/main.cpp\n";
                makefile.close();
                std::cout << "Project structure for '" << argv[1] << "' created successfully.\n";
            }
            if (argc > 3)
            {
                if (std::string(argv[3]) == "modul")
                {
                    std::filesystem::create_directories(argv[1]);
                    std::filesystem::create_directories(std::string(argv[1]) + "/src");
                    std::filesystem::create_directories(std::string(argv[1]) + "/includes");
                    std::filesystem::create_directories(std::string(argv[1]) + "/build");
                    std::ofstream inc_file(std::string(argv[1]) + "/includes/main.h");
                    inc_file << "#ifndef FILE_H\n"
                             << "#define FILE_H\n"
                             << "#include <iostream>\n"
                             << "#endif // FILE_H\n";
                    inc_file.close();
                    std::ofstream main_file(std::string(argv[1]) + "/src/main.cpp");
                    main_file << "#include <iostream>\n"
                              << "#include \"../includes/main.h\"\n\n"
                              << "int main() \n{\n"
                              << "    std::cout << \"Hello, World!\" << std::endl;\n"
                              << "    return 0;\n"
                              << "}\n";
                    main_file.close();
                    std::ofstream readme_file(std::string(argv[1]) + "/README.md");
                    readme_file.close();
                    std::ofstream makefile(std::string(argv[1]) + "/Makefile");
                    makefile << "all:\n"
                             << "\tg++ -o build/main src/main.cpp\n";
                    makefile.close();
                    std::ofstream project(std::string(argv[1]) + ".strprjproject.txt");
                    project << "prog";
                    project.close();
                    std::cout << "Project structure for '" << argv[1] << "' created successfully.\n";
                }
                else if (std::string(argv[3]) == "prog")
                {
                    std::filesystem::create_directories(argv[1]);
                    std::filesystem::create_directories(std::string(argv[1]) + "/src");
                    std::filesystem::create_directories(std::string(argv[1]) + "/includes");
                    std::filesystem::create_directories(std::string(argv[1]) + "/build");
                    std::ofstream main_file(std::string(argv[1]) + "/src/main.cpp");
                    main_file << "#include <iostream>\n\n"
                              << "int main() \n{\n"
                              << "    std::cout << \"Hello, World!\" << std::endl;\n"
                              << "    return 0;\n"
                              << "}\n";
                    main_file.close();
                    std::ofstream readme_file(std::string(argv[1]) + "/README.md");
                    readme_file.close();
                    std::ofstream makefile(std::string(argv[1]) + "/Makefile");
                    makefile << "all:\n"
                             << "\tg++ -o build/main src/main.cpp\n";
                    makefile.close();
                    std::ofstream project(std::string(argv[1]) + ".strprjproject.txt");
                    project << "modul";
                    project.close();
                    std::cout << "Project structure for '" << argv[1] << "' created successfully.\n";
                }
            }
        }
        else if (std::string(argv[2]) == "java")
        {
            std::filesystem::create_directories(argv[1]);
            std::filesystem::create_directories(std::string(argv[1]) + "/src");
            std::filesystem::create_directories(std::string(argv[1]) + "/lib");
            std::ofstream main_file(std::string(argv[1]) + "/src/Main.java");
            main_file << "public class Main {\n"
                      << "    public static void main(String[] args) {\n"
                      << "        System.out.println(\"Hello, World!\");\n"
                      << "    }\n"
                      << "}\n";
            main_file.close();
            std::ofstream readme_file(std::string(argv[1]) + "/README.md");
            readme_file.close();
            std::cout << "Project structure for '" << argv[1] << "' created successfully.\n";
        }
        else if (std::string(argv[2]) == "javascript")
        {
            std::filesystem::create_directories(argv[1]);
            std::filesystem::create_directories(std::string(argv[1]) + "/src");
            std::filesystem::create_directories(std::string(argv[1]) + "/tests");
            std::ofstream main_file(std::string(argv[1]) + "/src/main.js");
            main_file << "console.log('Hello, World!');\n";
            main_file.close();
            std::ofstream readme_file(std::string(argv[1]) + "/README.md");
            readme_file.close();
            std::ofstream package_json(std::string(argv[1]) + "/package.json");
            package_json << "{\n"
                         << "  \"name\": \"" << argv[1] << "\",\n"
                         << "  \"version\": \"0.1.0\",\n"
                         << "  \"main\": \"src/main.js\",\n"
                         << "  \"scripts\": {\n"
                         << "    \"start\": \"node src/main.js\"\n"
                         << "  }\n"
                         << "}\n";
            package_json.close();
            std::cout << "Project structure for '" << argv[1] << "' created successfully.\n";
        }
        else if (std::string(argv[2]) == "rust")
        {
            std::filesystem::create_directories(argv[1]);
            std::filesystem::create_directories(std::string(argv[1]) + "/src");
            std::ofstream main_file(std::string(argv[1]) + "/src/main.rs");
            main_file << "fn main() {\n"
                      << "    println!(\"Hello, World!\");\n"
                      << "}\n";
            main_file.close();
            std::ofstream readme_file(std::string(argv[1]) + "/README.md");
            readme_file.close();
            std::ofstream cargo_file(std::string(argv[1]) + "/Cargo.toml");
            cargo_file << "[package]\n"
                       << "name = \"" << argv[1] << "\"\n"
                       << "version = \"0.1.0\"\n"
                       << "edition = \"2018\"\n\n"
                       << "[dependencies]\n";
            cargo_file.close();
            std::ofstream lib_file(std::string(argv[1]) + "/src/lib.rs");
            lib_file << "pub fn hello() {\n"
                     << "    println!(\"Hello, World!\");\n"
                     << "}\n";
            lib_file.close();
            std::filesystem::create_directories(std::string(argv[1]) + "/tests");
            std::ofstream test_file(std::string(argv[1]) + "/tests/test.rs");
            test_file.close();
            std::filesystem::create_directories(std::string(argv[1]) + "/examples");
            std::filesystem::create_directories(std::string(argv[1]) + "/benches");
            std::ofstream test_file2(std::string(argv[1]) + "/Cargo.lock");
            test_file2.close();
            std::cout << "Project structure for '" << argv[1] << "' created successfully.\n";
        }
        else if (std::string(argv[2]) == "go")
        {
            std::filesystem::create_directories(argv[1]);
            std::filesystem::create_directories(std::string(argv[1]) + "/cmd");
            std::filesystem::create_directories(std::string(argv[1]) + "/pkg");
            std::ofstream main_file(std::string(argv[1]) + "/cmd/main.go");
            main_file << "package main\n\n"
                      << "import \"fmt\"\n\n"
                      << "func main() {\n"
                      << "    fmt.Println(\"Hello, World!\")\n"
                      << "}\n";
            main_file.close();
            std::ofstream readme_file(std::string(argv[1]) + "/README.md");
            readme_file.close();
            std::cout << "Project structure for '" << argv[1] << "' created successfully.\n";
        }
        else if (std::string(argv[2]) == "php")
        {
            std::filesystem::create_directories(argv[1]);
            std::filesystem::create_directories(std::string(argv[1]) + "/src");
            std::ofstream main_file(std::string(argv[1]) + "/src/index.php");
            main_file << "<?php\n"
                      << "echo 'Hello, World!';\n";
            main_file.close();
            std::ofstream readme_file(std::string(argv[1]) + "/README.md");
            readme_file.close();
            std::cout << "Project structure for '" << argv[1] << "' created successfully.\n";
        }
        else if (std::string(argv[2]) == "ruby")
        {
            std::filesystem::create_directories(argv[1]);
            std::filesystem::create_directories(std::string(argv[1]) + "/lib");
            std::ofstream main_file(std::string(argv[1]) + "/lib/main.rb");
            main_file << "puts 'Hello, World!'\n";
            main_file.close();
            std::ofstream readme_file(std::string(argv[1]) + "/README.md");
            readme_file.close();
            std::cout << "Project structure for '" << argv[1] << "' created successfully.\n";
        }
        else if (std::string(argv[2]) == "swift")
        {
            std::filesystem::create_directories(argv[1]);
            std::filesystem::create_directories(std::string(argv[1]) + "/Sources");
            std::ofstream main_file(std::string(argv[1]) + "/Sources/main.swift");
            main_file << "print(\"Hello, World!\")\n";
            main_file.close();
            std::ofstream readme_file(std::string(argv[1]) + "/README.md");
            readme_file.close();
            std::cout << "Project structure for '" << argv[1] << "' created successfully.\n";
        }
        else if (std::string(argv[2]) == "kotlin")
        {
            std::filesystem::create_directories(argv[1]);
            std::filesystem::create_directories(std::string(argv[1]) + "/src");
            std::ofstream main_file(std::string(argv[1]) + "/src/Main.kt");
            main_file << "fun main() {\n"
                      << "    println(\"Hello, World!\")\n"
                      << "}\n";
            main_file.close();
            std::ofstream readme_file(std::string(argv[1]) + "/README.md");
            readme_file.close();
            std::cout << "Project structure for '" << argv[1] << "' created successfully.\n";
        }
        else if (std::string(argv[2]) == "typescript")
        {
            std::filesystem::create_directories(argv[1]);
            std::filesystem::create_directories(std::string(argv[1]) + "/src");
            std::ofstream main_file(std::string(argv[1]) + "/src/main.ts");
            main_file << "console.log('Hello, World!');\n";
            main_file.close();
            std::ofstream readme_file(std::string(argv[1]) + "/README.md");
            readme_file.close();
            std::ofstream tsconfig_file(std::string(argv[1]) + "/tsconfig.json");
            tsconfig_file << "{\n"
                          << "  \"compilerOptions\": {\n"
                          << "    \"target\": \"es6\",\n"
                          << "    \"module\": \"commonjs\"\n"
                          << "  }\n"
                          << "}\n";
            tsconfig_file.close();
            std::cout << "Project structure for '" << argv[1] << "' created successfully.\n";
        }
        else if (std::string(argv[2]) == "dart")
        {
            std::filesystem::create_directories(argv[1]);
            std::filesystem::create_directories(std::string(argv[1]) + "/lib");
            std::ofstream main_file(std::string(argv[1]) + "/lib/main.dart");
            main_file << "void main() {\n"
                      << "  print('Hello, World!');\n"
                      << "}\n";
            main_file.close();
            std::ofstream readme_file(std::string(argv[1]) + "/README.md");
            readme_file.close();
            std::cout << "Project structure for '" << argv[1] << "' created successfully.\n";
        }
        else if (std::string(argv[2]) == "scala")
        {
            std::filesystem::create_directories(argv[1]);
            std::filesystem::create_directories(std::string(argv[1]) + "/src");
            std::ofstream main_file(std::string(argv[1]) + "/src/Main.scala");
            main_file << "object Main {\n"
                      << "    def main(args: Array[String]): Unit = {\n"
                      << "        println(\"Hello, World!\")\n"
                      << "    }\n"
                      << "}\n";
            main_file.close();
            std::ofstream readme_file(std::string(argv[1]) + "/README.md");
            readme_file.close();
            std::cout << "Project structure for '" << argv[1] << "' created successfully.\n";
        }
        else if (std::string(argv[2]) == "elixir")
        {
            std::filesystem::create_directories(argv[1]);
            std::filesystem::create_directories(std::string(argv[1]) + "/lib");
            std::ofstream main_file(std::string(argv[1]) + "/lib/main.exs");
            main_file << "IO.puts \"Hello, World!\"\n";
            main_file.close();
            std::ofstream readme_file(std::string(argv[1]) + "/README.md");
            readme_file.close();
            std::cout << "Project structure for '" << argv[1] << "' created successfully.\n";
        }
        else if (std::string(argv[2]) == "haskell")
        {
            std::filesystem::create_directories(argv[1]);
            std::ofstream main_file(std::string(argv[1]) + "/Main.hs");
            main_file << "main :: IO ()\n"
                      << "main = putStrLn \"Hello, World!\"\n";
            main_file.close();
            std::ofstream readme_file(std::string(argv[1]) + "/README.md");
            readme_file.close();
            std::cout << "Project structure for '" << argv[1] << "' created successfully.\n";
        }
        else if (std::string(argv[2]) == "c#")
        {
            std::filesystem::create_directories(argv[1]);
            std::filesystem::create_directories(std::string(argv[1]) + "/src");
            std::ofstream main_file(std::string(argv[1]) + "/src/Program.cs");
            main_file << "using System;\n\n"
                      << "class Program {\n"
                      << "    static void Main() {\n"
                      << "        Console.WriteLine(\"Hello, World!\");\n"
                      << "    }\n"
                      << "}\n";
            main_file.close();
            std::ofstream readme_file(std::string(argv[1]) + "/README.md");
            readme_file.close();
            std::cout << "Project structure for '" << argv[1] << "' created successfully.\n";
        }
        else if (std::string(argv[2]) == "lua")
        {
            std::filesystem::create_directories(argv[1]);
            std::filesystem::create_directories(std::string(argv[1]) + "/src");
            std::ofstream main_file(std::string(argv[1]) + "/src/main.lua");
            main_file << "print('Hello, World!')\n";
            main_file.close();
            std::ofstream readme_file(std::string(argv[1]) + "/README.md");
            readme_file.close();
            std::cout << "Project structure for '" << argv[1] << "' created successfully.\n";
        }
        else if (std::string(argv[2]) == "shell")
        {
            std::filesystem::create_directories(argv[1]);
            std::ofstream main_file(std::string(argv[1]) + "/main.sh");
            main_file << "#!/bin/bash\n"
                      << "echo 'Hello, World!'\n";
            main_file.close();
            std::ofstream readme_file(std::string(argv[1]) + "/README.md");
            readme_file.close();
            std::cout << "Project structure for '" << argv[1] << "' created successfully.\n";
        }
        else if (std::string(argv[2]) == "r")
        {
            std::filesystem::create_directories(argv[1]);
            std::ofstream main_file(std::string(argv[1]) + "/main.R");
            main_file << "print('Hello, World!')\n";
            main_file.close();
            std::ofstream readme_file(std::string(argv[1]) + "/README.md");
            readme_file.close();
            std::cout << "Project structure for '" << argv[1] << "' created successfully.\n";
        }
        else if (std::string(argv[2]) == "perl")
        {
            std::filesystem::create_directories(argv[1]);
            std::filesystem::create_directories(std::string(argv[1]) + "/src");
            std::ofstream main_file(std::string(argv[1]) + "/src/main.pl");
            main_file << "print 'Hello, World!';\n";
            main_file.close();
            std::ofstream readme_file(std::string(argv[1]) + "/README.md");
            readme_file.close();
            std::cout << "Project structure for '" << argv[1] << "' created successfully.\n";
        }
        else if (std::string(argv[2]) == "objective-c")
        {
            std::filesystem::create_directories(argv[1]);
            std::filesystem::create_directories(std::string(argv[1]) + "/src");
            std::ofstream main_file(std::string(argv[1]) + "/src/main.m");
            main_file << "#import <Foundation/Foundation.h>\n\n"
                      << "int main(int argc, const char * argv[]) {\n"
                      << "    @autoreleasepool {\n"
                      << "        NSLog(@\"Hello, World!\");\n"
                      << "    }\n"
                      << "    return 0;\n"
                      << "}\n";
            main_file.close();
            std::ofstream readme_file(std::string(argv[1]) + "/README.md");
            readme_file.close();
            std::cout << "Project structure for '" << argv[1] << "' created successfully.\n";
        }
        else
        {
            std::cout << "Error: Unsupported project type. Use 'python' or 'cpp'.\n";
            return 1;
        }
    }
    return 0;
}
