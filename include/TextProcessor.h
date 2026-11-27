#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H

#include <string>

// Обработка текста из файла с помощью файловых и строковых потоков
class TextProcessor {
private:
    std::string fileName;

    static bool nextWord(const std::string& source, size_t& pos, std::string& word);
    static bool containsWord(const std::string& sentence, const std::string& word);
    static void processSentence(const std::string& sentence, const std::string& word, int& found);

public:
    TextProcessor();
    TextProcessor(const std::string& fileName);
    TextProcessor(const TextProcessor& other);
    ~TextProcessor();

    TextProcessor& operator=(const TextProcessor& other);

    std::string getFileName() const;
    void setFileName(const std::string& fileName);

    std::string readText() const;                                   // читает весь файл (ifstream + ostringstream)
    void printSentencesWithWord(const std::string& word) const;    // только предложения с заданным словом
};

#endif