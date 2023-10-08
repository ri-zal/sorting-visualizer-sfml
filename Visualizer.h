#ifndef SORTING_VISUALIZER___SFML_VISUALIZER_H
#define SORTING_VISUALIZER___SFML_VISUALIZER_H

#include <SFML/Graphics.hpp>
#include <random>

class Visualizer {
private:
    int window_width = 800;
    int window_height = 600;
    sf::RenderWindow window;
    sf::Font font;
    sf::Text info;
    sf::Clock clock;

    static const int SIZE = 50;
    int data[SIZE];
    int data_copy[SIZE];

    void InitWindow();
    bool LoadFont();

    void FillData();
    void DisplayData();
    int FindMax();
public:
    Visualizer();
    void Run();
    void DrawState();
    void CopyArr();

    // sorting algorithms
    void BubbleSort();
    void InsertionSort();
    void CountingSort();
};


#endif //SORTING_VISUALIZER___SFML_VISUALIZER_H