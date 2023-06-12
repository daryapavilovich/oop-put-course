#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class IntegerSequence {
public:
    virtual std::vector<int> Numbers() = 0;
};
class VectorSequence : public IntegerSequence {
private:
    std::vector<int> sequence;

public:
    VectorSequence(std::vector<int> seq) : sequence(seq) {}

    std::vector<int> Numbers() override {
        return sequence;
    }
};
class PositiveSequence : public IntegerSequence {
private:
    IntegerSequence* sequence;

public:
    PositiveSequence(IntegerSequence* seq) : sequence(seq) {}

    std::vector<int> Numbers() override {
        std::vector<int> numbers = sequence->Numbers();
        std::vector<int> positiveNumbers;

        for (int number : numbers) {
            if (number >= 0) {
                positiveNumbers.push_back(number);
            }
        }

        return positiveNumbers;
    }
};
class EvenSequence : public IntegerSequence {
private:
    IntegerSequence* sequence;
public:
    EvenSequence(IntegerSequence* seq) : sequence(seq) {}

vector<int> Numbers() override {
vector<int> numbers = sequence->Numbers();
vector<int> evenNumbers;
for (int number : numbers) {
if (number % 2 == 0) {
    evenNumbers.push_back(number);
            }
        }

        return evenNumbers;
    }
};
class SortedSequence : public IntegerSequence {
private:
    IntegerSequence* sequence;
public:
    SortedSequence(IntegerSequence* seq) : sequence(seq) {}

    vector<int> Numbers() override {
        vector<int> numbers = sequence->Numbers();
        sort(numbers.begin(), numbers.end());
        return numbers;
    }
};

int main() {
    vector<int> inputSequence = { 5, -3, 10, -2, 7, 0, 1, -8, 4 };

    IntegerSequence* sequence = new VectorSequence(inputSequence);
    sequence = new PositiveSequence(sequence);
    sequence = new EvenSequence(sequence);
    sequence = new SortedSequence(sequence);

    vector<int> result = sequence->Numbers();

    cout << "Processed Sequence: ";
    for (int number : result) {
        cout << number << " ";
    }
    cout <<endl;
    delete sequence;
    return 0;
}
