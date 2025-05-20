#include "ToneAnalysis.h"
#include <algorithm>

using namespace OSmetod;

ToneAnalysis::ToneAnalysis() {
    analyzer = new ToneAnalyzer();
    onprogress = nullptr;
}

ToneAnalysis::ToneAnalysis(std::string* text) : ToneAnalysis() {
    analyzer->setdata(text);
}

ToneAnalysis::~ToneAnalysis() {
    delete analyzer;
}

bool ToneAnalysis::sort() {
    return analyzer->execute(onprogress);
}

ToneAnalyzer::ToneAnalyzer() {
    text = new std::string();
    analysisTime = 0;
    initializeDictionaries();
}

ToneAnalyzer::ToneAnalyzer(std::string* inputText) : ToneAnalyzer() {
    text->assign(*inputText);
}

ToneAnalyzer::~ToneAnalyzer() {
    delete text;
}

void ToneAnalyzer::setdata(std::string* inputText) {
    text->assign(*inputText);
}

std::string* ToneAnalyzer::getdata() {
    return text;
}

std::string ToneAnalyzer::getResult() {
    return result;
}

void ToneAnalyzer::initializeDictionaries() {
    // Приклади слів (для демонстрації)
    positiveWords = { "happy", "great", "wonderful", "awesome", "love", "good" };
    negativeWords = { "sad", "bad", "terrible", "hate", "awful", "angry" };
    neutralWords = { "okay", "normal", "usual", "fine", "standard" };
}

bool ToneAnalyzer::execute(OnProgressEvent^ onprogress) {
    try {
        analysisTime = time(NULL);
        // Перетворення тексту в нижній регістр і розбиття на слова
        std::string input = *text;
        std::transform(input.begin(), input.end(), input.begin(), ::tolower);
        std::vector<std::string> words;
        std::string word;
        for (char c : input) {
            if (std::isalpha(c) || c == '\'') {
                word += c;
            }
            else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        if (!word.empty()) words.push_back(word);

        // Підрахунок тональності
        int positiveCount = 0, negativeCount = 0, neutralCount = 0;
        for (size_t i = 0; i < words.size(); ++i) {
            if (positiveWords.count(words[i])) positiveCount++;
            else if (negativeWords.count(words[i])) negativeCount++;
            else if (neutralWords.count(words[i])) neutralCount++;
            if (onprogress) onprogress(static_cast<float>(i + 1) * 100.0f / words.size());
        }

        // Визначення тональності
        if (positiveCount > negativeCount && positiveCount > neutralCount) {
            result = "Positive";
        }
        else if (negativeCount > positiveCount && negativeCount > neutralCount) {
            result = "Negative";
        }
        else {
            result = "Neutral";
        }

        analysisTime = difftime(time(NULL), analysisTime);
        return true;
    }
    catch (...) {
        result = "Error";
        return false;
    }
}