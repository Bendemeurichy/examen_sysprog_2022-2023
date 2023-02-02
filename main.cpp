#include <iostream>

#include "custom_string.hpp"
#include "quick_map.hpp"

/**
 * @warning Aanpassingen in dit bestand staan niet op punten,
 * MAAR zorg er voor dat jullie finale indiening compileert (zet hiervoor eventueel code in comment)
 */

int main(int argc, char **argv) {

    /* custom_string */
    // Voorbeeld uit opgave
    custom_string my_string("systeemprogrammeren <3");
    std::cout << my_string << std::endl;

    // Eventueel eigen code om de functionaliteit te testen (staat niet op punten)

    /* quick_map */
    // Voorbeelden uit opgave
    quick_map my_quick_map(3);
    my_quick_map.insert("a", 11.9);
    my_quick_map.insert("b", 7.0);
    my_quick_map.insert("d", 0.7);
    my_quick_map.insert("e", 48.2);
    my_quick_map.insert("f", 67.4);

    std::cout << my_quick_map << std::endl;

    my_quick_map.print_smallest_values();
    my_quick_map.print_largest_values();

    // Voorbeeld van pair constructor
    std::pair<const custom_string, double> elements[3] = {std::make_pair("a", 31.9), std::make_pair("b", 7.0), std::make_pair("d", 1.7)};
    quick_map my_pair_quick_map(2, elements, 3);
    std::cout << my_pair_quick_map << std::endl;

    // Eventueel eigen code om functionaliteit te testen (staat niet op punten)

    return 0;
}