#include "listofnumbers.h"


using namespace std;

ListOfNumbers::ListOfNumbers()
{

}

void ListOfNumbers::menu() {

    char choice {};
    vector<long double> number_list {};

    do {

        cout << "[P] Print Numbers\n[A] Add a number\n[M] Display mean of the numbers\n[S] Display the smallest number\n[L] Display the largest number\n[K] Look for number\n[C] Clear list\n[Q] Quit\n\nEnter your choice: ";
        cin >> choice;

        choice = static_cast<char>(tolower(choice));        // Input is lowercased for simpler if expressions

        if (choice == 'p') {

            printNumbers(number_list);

        } else if (choice == 'a') {

            number_list = addNumber(number_list);

        } else if (choice == 'm') {

            calculateMean(number_list);

        } else if (choice == 's') {

            getSmallestNumber(number_list);

        } else if (choice == 'l') {

            getLargestNumber(number_list);

        } else if (choice == 'k') {

            countOccurences(number_list);

        } else if (choice == 'c') {
            number_list.clear();
            cout << "The list has been cleared!\n\n";
        } else if (choice == 'q') {
            cout << "Goodbye!" << endl;
        } else {
            cout << "Unknown selection, please try again\n\n";
        }

    } while ( choice != 'q');

}

vector<long double> ListOfNumbers::addNumber(vector<long double> numbers_list) {

    string added_number {};

    cout << "Please add a number: ";
    cin >> added_number;

    try
    {
        long double i = std::stold(added_number);       // Converses string to long double
        numbers_list.push_back(i);
        cout << i << " added\n\n";
    }
    catch (std::invalid_argument const &e)
    {
        cout << "Illegal choice, please choose an integer\n\n";
    }
    catch (std::out_of_range const &e)
    {
        cout << "Error, too big/too small number\n\n";
    }

    return numbers_list;

}

void ListOfNumbers::printNumbers(vector<long double> numbers_list) {

    if (numbers_list.size() <= 0) {
        cout << "[] - the list is empty\n\n";
    } else {
        cout << "[ ";
        for ( long double e : numbers_list) {
            cout << e << " ";
        }
        cout << "]\n\n";
    }

}

void ListOfNumbers::calculateMean(std::vector<long double> numbers_list) {

    if ( numbers_list.size() <= 0 ) {
        cout << "Unable to calculate the mean - no data\n\n";
    } else {
        long double sum {};
        long double mean {};
        for ( long double e : numbers_list) {
            sum += e;
        }
        mean = sum / static_cast<long double>(numbers_list.size()) ;
        cout << "The mean is " << mean << "\n\n";
    }

}

void ListOfNumbers::getSmallestNumber(std::vector<long double> numbers_list) {

    if ( numbers_list.size() <= 0 ) {
        cout << "Unable to determine smalles number - list is empty\n\n";
    } else {
        long double smallest_number {};
        // type is unsigned long long to ensure same type comparison, since vector size type is ull
        for ( unsigned long long i {1} ; i < numbers_list.size(); i++ ) {

            smallest_number = numbers_list.at(0);
            if ( numbers_list.at(i) <  smallest_number ) {
                smallest_number = numbers_list.at(i);
            }
        }

        cout << "The smallest number is " << smallest_number << "\n\n";
    }

}

void ListOfNumbers::getLargestNumber(std::vector<long double> numbers_list) {

    if ( numbers_list.size() <= 0 ) {
        cout << "Unable to determine largest number - list is empty\n\n";
    } else {
        long double largest_number {};
        for ( unsigned long long i {1} ; i < numbers_list.size(); i++ ) {

            largest_number = numbers_list.at(0);
            if ( numbers_list.at(i) >  largest_number ) {
                largest_number = numbers_list.at(i);
            }
        }
        cout << "The largest number is " << largest_number << "\n\n";
    }

}

void ListOfNumbers::countOccurences(std::vector<long double> numbers_list) {

    string look_for_number {};

    cout << "Please choose a number: ";
    cin >> look_for_number;

    try
    {
        long double i = std::stold(look_for_number);
        int occurences {};
        for ( auto e : numbers_list ) {
            // Due to floating point precision, expression evaluates to true if the result is around 0
            if ( fabs(i - e) < 0.005L && fabs(i - e) > -0.005L ) {
                occurences++;
            }
        }
        cout << "The number " << i << " occurs " << occurences << " times\n\n";
    }
    catch (std::invalid_argument const &e)
    {
        cout << "Illegal choice, please choose an integer\n\n";
    }
    catch (std::out_of_range const &e)
    {
        cout << "Error, too big/too small number\n\n";
    }


}

