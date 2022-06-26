# Complexity

Complexity: O(N)  with N is the max length between two documents

# Complexity Analysis:  
- We use unordered_map (hash table) for storing words and their frequency thus would have the following complexity:
  - Hashing is required and hasing complexity depends on the length of each word: O(s.length) where s.length is max length of all words in two document
  - Looking up whether an element is in the map : O(1) average and O(n) worse (as collision resolving using bucket)
  - Insertion: O(1) average
- Dot product: O(N) with N is the max length between two documents
- Euclidean norm: O(N)  

Thus total complexity is O(N) (though we could use O(N*s.length) I suppose that s.length is likely to be small and thus can be eliminated)

# Suggestion for a better formula
Another approach would be using the Euclidean distance. That is we see the two documents as two point with N dimension (each feature is independent of others) and we show their differences by measuring their Eulidean distance (L2 norm)
