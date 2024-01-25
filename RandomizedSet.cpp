//
// Created by Simon To on 1/15/24.
//
#include <iostream>
#include <unordered_set>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class RandomizedSet {
private:
    // element_to_index stores el
    unordered_set<int> set;
    vector<int> elements;

public:

    /*

    We want to ensure O(1) access to any element within the array:
     1. We definitely need to keep the array sorted at all times to AVOID ANY SEARCHING
     2. This is particularly viable because we're keeping an array of integers, which has very
     easily comparable value.
     3. Some important values that we should be aware of in our array:
        min = minimum value, which is also the leftest value in out array.
        max = maximum value, which is also the rightest value in out array.

     3. Given an int input, we do the following:
        1. Compare with min,
            1. If less than min:



    */


    /*
     * RandomizedSet() Initializes the RandomizedSet object.
     * bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
     * bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
     * int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.

     */


    RandomizedSet() {
        srand(time(0));
    }

    bool insert(int val) {
        /* unordered_set.insert will return a pair that contains the following:
         * first = an iterator to the element, regardless if the insertion actually happened or not.
         * second = a boolean indicating if the insertion attempt is successful.
         */
        // 1. Attempt to perform insertion on set:
        bool success = this->set.insert(val).second;

        // 2. Based on whether the insertion on set is successful, we decide if we want to perform insertion on elements
        // as well.
        if (success) {
            this->elements.push_back(val);
        }

        return success;
    }

    bool remove(int val) {
        /*
         * unordered_set.erase will return a boolean indicating if the deletion attempt is successful.
         */

        // 1. Attempt to perform erasure on set:
        bool success = this->set.erase(val);

        // 2. Based on whether the erasure on set is successful, we decide if we want to perform removal on elements
        // as well.
        if (success) {
            auto val_pos = find(elements.begin(), elements.end(), val);
            if (val_pos == elements.end()) {
                // This should NEVER HAPPEN!
                cout << "What the fuck is happening here?" << endl;
            }
            else {
                this->elements.erase(val_pos);
            }
        }

        return success;

    }

    int getRandom() {
        int random_index = rand() % elements.size(); // Get a random index to access the elements vector.
        return elements[random_index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */