#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class TrieNode {
public:
    TrieNode() : is_file(false) {}

    std::unordered_map<std::string, TrieNode*> children;
    bool is_file;
};

class FileSystem {
public:
    FileSystem() {
        root = new TrieNode();
    }

    ~FileSystem() {
        deleteTrie(root);
    }

    void create(const std::string& path) {
        TrieNode* node = getNode(path);
        if (!node) { // Path doesn't exist
            TrieNode* parent = nullptr;
            std::string name = getParentAndName(path, parent);
            parent->children[name] = new TrieNode();
            std::cout << "File created successfully." << std::endl;
        }
        else if (!node->is_file) { // A directory already exists with the same name
            std::cout << "Directory with the same name exists at the given path." << std::endl;
        }
        else { // A file already exists with the same name
            std::cout << "File with the same name exists at the given path." << std::endl;
        }
    }

    void rename(const std::string& old_path, const std::string& new_path) {
        TrieNode* old_node = getNode(old_path);
        TrieNode* new_node = getNode(new_path);

        if (!old_node) {
            std::cout << "The old path does not exist." << std::endl;
            return;
        }

        if (new_node) {
            std::cout << "The new path already exists." << std::endl;
            return;
        }

        TrieNode* old_parent = nullptr;
        std::string old_name = getParentAndName(old_path, old_parent);
        TrieNode* new_parent = nullptr;
        std::string new_name = getParentAndName(new_path, new_parent);

        new_parent->children[new_name] = old_node;
        old_parent->children.erase(old_name);
        std::cout << "File/directory renamed successfully." << std::endl;
    }

    void del(const std::string& path) {
        TrieNode* node = getNode(path);

        if (!node) {
            std::cout << "The path does not exist." << std::endl;
            return;
        }

        TrieNode* parent = nullptr;
        std::string name = getParentAndName(path, parent);
        parent->children.erase(name);
        std::cout << "File/directory deleted successfully." << std::endl;
    }

    void list(const std::string& path) {
        TrieNode* node = getNode(path);

        if (!node) {
            std::cout << "The path does not exist." << std::endl;
            return;
        }

        if (node->is_file) {
            std::cout << path << std::endl; // If the path represents a file, print the file name
        }
        else {
            // For directories, list all subdirectories and files recursively
            traverse(node, path);
        }
    }

private:
    TrieNode* root;

    void deleteTrie(TrieNode* node) {
        if (!node) {
            return;
        }

        for (auto& entry : node->children) {
            deleteTrie(entry.second);
        }

        delete node;
    }

    TrieNode* getNode(const std::string& path) {
        TrieNode* node = root;
        size_t start = 1; // Skip the root '/'
        size_t pos = path.find('/', start);

        while (pos != std::string::npos) {
            std::string name = path.substr(start, pos - start);
            if (node->children.count(name) == 0) {
                return nullptr; // Path does not exist
            }
            node = node->children[name];
            start = pos + 1;
            pos = path.find('/', start);
        }

        std::string name = path.substr(start);
        if (node->children.count(name) == 0) {
            return nullptr; // Path does not exist
        }
        return node->children[name];
    }

    std::string getParentAndName(const std::string& path, TrieNode*& parent) {
        parent = root;
        size_t start = 1; // Skip the root '/'
        size_t pos = path.find('/', start);

        while (pos != std::string::npos) {
            std::string name = path.substr(start, pos - start);
            if (parent->children.count(name) == 0) {
                parent->children[name] = new TrieNode();
            }
            parent = parent->children[name];
            start = pos + 1;
            pos = path.find('/', start);
        }

        std::string name = path.substr(start);
        return name;
    }

    void traverse(TrieNode* node, const std::string& path) {
        if (node->is_file) {
            std::cout << path << std::endl;
        }

        for (auto& entry : node->children) {
            traverse(entry.second, path + "/" + entry.first);
        }
    }
};

int main() {
    FileSystem fs;

    fs.create("/dir1");
    fs.create("/dir1/file1.txt");
    fs.create("/dir1/file2.txt");
    fs.create("/dir1/subdir");
    fs.create("/dir1/subdir/file3.txt");
    fs.create("/dir2");
    fs.create("/dir2/file4.txt");

    fs.list("/dir1");
    fs.list("/dir2");
    fs.list("/dir1/subdir");

    fs.rename("/dir2/file4.txt", "/dir2/newfile.txt");
    fs.rename("/dir2", "/dir3");

    fs.list("/dir2");
    fs.list("/dir3");

    fs.del("/dir1/subdir/file3.txt");
    fs.del("/dir2/newfile.txt");

    fs.list("/dir1/subdir");
    fs.list("/dir2");
    fs.list("/dir3");

    return 0;
}
