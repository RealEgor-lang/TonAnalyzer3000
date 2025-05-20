#pragma once
#include <string>
#include <vector>
#include <unordered_set>
#include <time.h>

namespace OSmetod {
    delegate void OnProgressEvent(float);

    class ToneAnalyzer {
    private:
        std::string* text;
        std::unordered_set<std::string> positiveWords;
        std::unordered_set<std::string> negativeWords;
        std::unordered_set<std::string> neutralWords;
        std::string result; // Позитивний, Негативний, Нейтральний
        void initializeDictionaries(); // Додаємо оголошення
    public:
        time_t analysisTime;
        ToneAnalyzer();
        ToneAnalyzer(std::string* text);
        ~ToneAnalyzer();
        void setdata(std::string* text);
        std::string* getdata();
        std::string getResult();
        bool execute(OnProgressEvent^ onprogress);
    };

    ref class ToneAnalysis {
    private:
        ToneAnalyzer* analyzer;
    public:
        OnProgressEvent^ onprogress;
        ToneAnalysis();
        ToneAnalysis(std::string* text);
        ~ToneAnalysis();
        property std::string* Data {
            std::string* get() { return analyzer->getdata(); }
            void set(std::string* text) { analyzer->setdata(text); }
        }
        property System::String^ Result {
            System::String^ get() { return gcnew System::String(analyzer->getResult().c_str()); }
        }
        property System::String^ Timer {
            System::String^ get() { return analyzer->analysisTime.ToString(); }
        }
        bool sort();
    };
}