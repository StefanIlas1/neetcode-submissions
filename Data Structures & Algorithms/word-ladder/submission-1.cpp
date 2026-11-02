
/*
=========================================================
LEETCODE 127 — WORD LADDER
ALGORITHM: BIDIRECTIONAL BFS (MEET IN THE MIDDLE)
=========================================================

1. GOAL
---------------------------------------------------------
- Find the shortest transformation sequence from
  beginWord to endWord.

- Each transformation changes exactly ONE character.
- Every new word must exist in wordList.
- Return the number of words in the shortest sequence.
- Return 0 if no valid transformation exists.

- Instead of searching from one end, run BFS from BOTH
  beginWord and endWord until the searches connect.


2. INITIAL CHECK
---------------------------------------------------------
- Use find(wordList.begin(), wordList.end(), endWord)
  to check whether endWord exists in wordList.

- find() returns an iterator pointing to the word
  if found, or wordList.end() if not found.

- If endWord doesn't exist OR beginWord == endWord,
  return 0 (following this solution's convention).

- || means OR.
- == checks whether two values are equal.


3. DATA STRUCTURES
---------------------------------------------------------
- m = wordList[0].size()
  This gives the number of CHARACTERS in one word.
  All words have the same length, so one is enough.

- wordSet:
  unordered_set<string> containing all valid words.
  Used to quickly check whether a word exists.

- qb and qe:
  Two queues, one starting from beginWord and
  the other starting from endWord.

- fromBegin and fromEnd:
  Two hashmaps tracking which words each BFS has
  visited and their distances from its starting word.

- We need TWO maps because we must know whether
  a word was visited by our search or the other search.


4. INITIALIZING THE SEARCHES
---------------------------------------------------------
- qb.push(beginWord):
  Add the starting word to the first queue.

- qe.push(endWord):
  Add the ending word to the second queue.

- fromBegin[beginWord] = 1
- fromEnd[endWord] = 1

  Record both starting words with distance 1.
  We start at 1 because we count WORDS, not edges.


5. EXPANDING THE SMALLER QUEUE
---------------------------------------------------------
- Continue while BOTH queues are not empty.

- Compare qb.size() and qe.size().

- If qb contains more words than qe, swap them.

- swap(qb, qe):
  Exchanges the entire contents of the two queues.

- swap(fromBegin, fromEnd):
  Exchanges the entire contents of both hashmaps.

- We swap BOTH so each queue remains paired with
  the correct distance tracker.

- After swapping, qb is the smaller queue and
  fromBegin is its corresponding distance map.

- Expanding means processing the words currently
  waiting in that queue and finding their neighbors.

- Expanding the smaller queue generally reduces
  the amount of work.


6. PROCESSING ONE BFS LEVEL
---------------------------------------------------------
- int size = qb.size():
  Save the number of words currently in the queue.

- Loop k from 0 to size - 1 to process ONLY
  the current BFS level.

- qb.front():
  Get the first word waiting in the queue.

- qb.pop():
  Remove that word from the queue.

- steps = fromBegin[word]:
  Get the current word's recorded distance
  from this search's starting point.


7. GENERATING NEIGHBOR WORDS
---------------------------------------------------------
- Loop i from 0 to m - 1.
  This goes through every CHARACTER POSITION.

- Loop c from 'a' through 'z'.
  This tries every possible replacement letter.

- If c == word[i], continue.
  We skip the original character because we
  need to change exactly one letter.

- Construct the neighbor using:

  word.substr(0, i) + c + word.substr(i + 1)

  word.substr(0, i):
  Gets everything BEFORE position i.

  c:
  The new replacement character.

  word.substr(i + 1):
  Gets everything AFTER position i.

- Example:
  word = "cat", i = 1, c = 'o'

  "c" + "o" + "t" = "cot"

- nei stands for NEIGHBOR.
  It represents the newly generated word.


8. CHECKING VALID NEIGHBORS
---------------------------------------------------------
- wordSet.count(nei):
  Returns 1 if the word exists, or 0 otherwise.

- !wordSet.count(nei):
  Means the neighbor is NOT in the valid word set.

- If the neighbor isn't valid, continue.
  This skips it and tries the next letter.


9. CHECKING IF THE SEARCHES HAVE MET
---------------------------------------------------------
- if (fromEnd.count(nei)):

  Check if the OTHER BFS has already visited
  this neighbor.

- If it has, the two searches have connected,
  so we have found the shortest transformation.

- Return:
  steps + fromEnd[nei]

  steps = distance from our side to the current word.
  fromEnd[nei] = distance from the other side
  to the neighboring word.

- Example:
  hit -> hot -> dot
                dog <- cog

  steps = 3 (hit, hot, dot)
  fromEnd["dog"] = 2 (cog, dog)

  Return 3 + 2 = 5 words.

- We RETURN instead of pushing the neighbor because
  we already found the answer and can stop searching.


10. CONTINUING THE CURRENT SEARCH
---------------------------------------------------------
- if (!fromBegin.count(nei)):

  Check if OUR CURRENT BFS has NOT visited
  this neighbor yet.

- If the word is new to our search:

  fromBegin[nei] = steps + 1;

  Record the neighbor's distance.
  It is one step farther than the current word.

  qb.push(nei);

  Add the neighbor to the queue so BFS can
  explore it later.

- push() means KEEP SEARCHING.
- return means STOP because we found the answer.

- The hashmaps also act as visited trackers,
  so we don't need separate visited sets.


11. IMPORTANT C++ SYNTAX
---------------------------------------------------------
- unordered_set = collection of unique values.
- unordered_map = hashmap of keys and values.
- queue = FIFO (first in, first out).

- .push() = add an element to a queue.
- .front() = read the first queue element.
- .pop() = remove the first queue element.
- .size() = number of elements.
- .empty() = check whether a collection is empty.
- .count() = check whether a key/value exists.
- .substr() = extract part of a string.
- swap(a, b) = exchange the contents of a and b.
- continue = skip the rest of this loop iteration.

- nei = neighbor.
- m = number of characters in each word.
- steps = distance to the current word.
- qb = queue currently being expanded.
- qe = queue from the opposite search.


12. OVERALL ALGORITHM
---------------------------------------------------------
1. Check that endWord exists.
2. Find the length of each word.
3. Create the word set.
4. Initialize two queues and two distance maps.
5. Add beginWord and endWord to their queues.
6. Set both starting distances to 1.
7. Continue BFS while both queues are nonempty.
8. Swap queues/maps if needed to expand the smaller one.
9. Process every word in the current BFS level.
10. Generate neighbors by changing one character.
11. Skip neighbors not in wordSet.
12. If the other search visited the neighbor,
    return the sum of the two distances.
13. Otherwise, record new neighbors and enqueue them.
14. Return 0 if the searches never connect.

=========================================================
*/


// =======================================================
// BLANK IMPLEMENTATION — TRY IT FROM SCRATCH
// =======================================================


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end() || beginWord == endWord) { return 0;}
        
        int m = wordList[0].size();
        queue<string> qb, qe;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        unordered_map<string, int> begStart, endStart;
        qb.push(beginWord);
        qe.push(endWord);
        begStart[beginWord] = 1;
        endStart[endWord] = 1;

        while(!qe.empty() && !qb.empty()) {
            if(qb.size() > qe.size()) {
                swap(qb, qe);
                swap(begStart, endStart);
            }  

            int size = qb.size();
            for(int i = 0; i < size; i++) {
                string word = qb.front(); qb.pop();
                int steps = begStart[word];

                for(int k = 0; k < m; k++) {
                    for(char c = 'a'; c <= 'z'; c++) {
                        string nei = word.substr(0, k) + c + word.substr(k + 1);
                    
                        if(c == word[k]) continue;

                        if(!wordSet.count(nei)) {continue;}
                        if(endStart.count(nei)) {return steps + endStart[nei]; }
                        if(!begStart.count(nei)) {
                            begStart[nei] = steps + 1;
                            qb.push(nei);
                        }
                    }
                }
            }
        }
        return 0;
        
    }
};
