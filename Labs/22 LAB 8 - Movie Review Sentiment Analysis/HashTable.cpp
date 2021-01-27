#include "HashTable.h"

/* HashTable constructor
 *  input s is the size of the array
 *  set s to be size
 *  initialize array of lists of WordEntry
 */
HashTable::HashTable(size_t size)
    : hashTable_(new list<WordEntry>[size]), size_(size) {}

HashTable::~HashTable() {
  for (size_t i = 0; i < size_; i++) hashTable_[i].clear();
  delete [] hashTable_;
}

/* computeHash
 *  return an unsigned integer based on the input string
 *  used for index into the array in hash table
 *  be sure to use the size of the array to ensure array
 *  index doesn't go out of bounds
 */
size_t HashTable::computeHash(const string &s) const {
  int count = 0;
  int val = 0;

  for (unsigned i = 0; i < s.size(); i++) {
    count += s[i];
  }

  val = count % size_;

  return val;
}

/* put
 *  input: string word and int score to be inserted
 *  First, look to see if word already exists in hash table
 *   if so, addNewAppearence with the score to the WordEntry
 *   if not, create a new Entry and push it on the list at the
 *   appropriate array index
 */
void HashTable::put(const string &s, unsigned long score) {
  int val = computeHash(s);

  for (list<WordEntry>::iterator i = hashTable_[val].begin(); i != hashTable_[val].end(); i++) {
    if (i->getWord() == s) {
      i->addNewAppearance(score);
      return;
    }
  }

  WordEntry newEntry = WordEntry(s, score);
  hashTable_[val].push_back(newEntry);

}

/* getAverage
 *  input: string word
 *  output: the result of a call to getAverage()
 *          from the WordEntry
 *  Must first find the WordEntry in the hash table
 *  then return the average
 *  If not found, return the value 2.0 (neutral result)
 */

double HashTable::getAverage(const string &s) const {
  int val = computeHash(s);

  for (list<WordEntry>::iterator i = hashTable_[val].begin(); i != hashTable_[val].end(); i++) {
    if (i->getWord() == s) {
      return i->getAverage();
    }
  }

  return 2.0;
}

/* contains
 * input: string word
 * output: true if word is in the hash table
 *         false if word is not in the hash table
 */
bool HashTable::contains(const string &s) const {
  int val = computeHash(s);

  for (list<WordEntry>::iterator i = hashTable_[val].begin(); i != hashTable_[val].end(); i++) {
    if (i->getWord() == s) {
      return true;
    }
  }

  return false;
}
