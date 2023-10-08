#include "Visualizer.h"
#include <iostream>
#include <vector>

void Visualizer::DisplayData() {
    for (int i : data) {
        std::cout << i << " ";
    }
}

void Visualizer::InitWindow() {
    window.create(sf::VideoMode(window_width, window_height),
                  "Sorting Visualizer");
    window.clear(sf::Color::Black);
    window.display();
}

bool Visualizer::LoadFont() {
    if (!font.loadFromFile("../Arial.ttf")) {
        return false;
    }
    return true;
}

void Visualizer::FillData() {
    std::random_device rd;
    std::uniform_int_distribution<int> d(1, 100);
    for (int &i : data) {
        i = d(rd);
    }
}

Visualizer::Visualizer() {
    InitWindow();
    if (!LoadFont()) {
        std::cout << "Failed to load font." << std::endl;
    }
    FillData();
}

void Visualizer::Run() {
    while (window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if(event.type == sf::Event::KeyPressed) {
                switch(event.key.code) {
                    case sf::Keyboard::Num1:
                        CopyArr();
                        BubbleSort();
                        break;
                    case sf::Keyboard::Num2:
                        CopyArr();
                        InsertionSort();
                        break;
                    case sf::Keyboard::Num3:
                        CopyArr();
                        CountingSort();
                        break;
                    case sf::Keyboard::Q:
                        window.close();
                        break;
                    default:
                        break;
                }
            }
        }
    }
}

void Visualizer::DrawState() {
    window.clear(sf::Color::Black);
    int bar_width = window_width / SIZE;
    int bar_height;

    for (int i = 0; i < SIZE; i++) {
        int x = i * bar_width;
        bar_height = window_height - data_copy[i];

        sf::RectangleShape bar(sf::Vector2f(bar_width, bar_height));
        bar.setPosition(x, bar_height);
        bar.setFillColor(sf::Color::White);
        window.draw(bar);
    }

    window.display();
}

void Visualizer::CopyArr() {
    std::copy(data, data + SIZE, data_copy);
}

// sorting algorithms
void Visualizer::BubbleSort() {
    int n = SIZE;
    bool swapped;
    do {
        swapped = false;
        for (int i = 1; i < n; i++) {
            if (data_copy[i - 1] > data_copy[i]) {
                std::swap(data_copy[i - 1], data_copy[i]);
                swapped = true;
                DrawState();
                sf::sleep(sf::milliseconds(10));
            }
        }
        n--;
    } while (swapped);
}

void Visualizer::InsertionSort() {
    for (int i = 1; i < SIZE; i++) {
        int key = data_copy[i];
        int j = i - 1;

        while (j >= 0 && data_copy[j] > key) {
            data_copy[j + 1] = data_copy[j];
            j--;

            DrawState();
            sf::sleep(sf::milliseconds(10));
        }

        data_copy[j + 1] = key;
    }
}

int Visualizer::FindMax() {
    int max = data[0];
    for (int i = 1; i < SIZE; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }
    return max;
}

void Visualizer::CountingSort() {
    int max = FindMax();
    int min = 0;
    int range = max - min + 1;
    std::vector<int> count(range, 0);
    std::vector<int> output(SIZE);

    for (int i = 0; i < SIZE; i++) {
        count[data_copy[i] - min]++;
    }
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }
    for (int i = SIZE - 1; i >= 0; i--) {
        output[count[data_copy[i] - min] - 1] = data_copy[i];
        count[data_copy[i] - min]--;
    }

    for (int i = 0; i < SIZE; i++) {
        data_copy[i] = output[i];
        DrawState();
        sf::sleep(sf::milliseconds(50));
    }

}