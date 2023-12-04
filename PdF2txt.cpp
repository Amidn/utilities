#include <iostream>
#include <poppler-document.h>
#include <poppler-page.h>

int main() {
    std::string pdfPath, textPath;

    // Input PDF file path
    std::cout << "Enter the PDF file path: ";
    std::getline(std::cin, pdfPath);

    // Input text file path
    std::cout << "Enter the text file path: ";
    std::getline(std::cin, textPath);

    poppler::document* doc = poppler::document::load_from_file(pdfPath.c_str());

    if (!doc) {
        std::cerr << "Error loading PDF file.\n";
        return 1;
    }

    std::string text;

    for (int i = 0; i < doc->pages(); ++i) {
        poppler::page* page = doc->create_page(i);
        text += page->text().to_string();
    }

    delete doc;

    std::ofstream textFile(textPath);
    textFile << text;
    textFile.close();

    std::cout << "Text extracted and saved successfully.\n";

    return 0;
}
