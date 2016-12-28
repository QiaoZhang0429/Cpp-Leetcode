//fixed length encoding
//complete binary tree
//M symbol
//good for uniform dist
int avgLen = ceil(log(M,2));

//variable length encoding
//Variable length codes have to necessarily be prefix codes for correct decoding
//A prefix code is one where no symbol’s codeword is a prefix of another
[symbol, frequency]

//Huffman
//encoding a symbol: maintain a list of leaves and then to traverse the tree to the root
//start from a forest
//pick two smallest and merge until one
//implemented with priority_queue
//header
//O(k+nlogn)

//optimal code
//The entropy of the frequency distribution of the letters defines the minimum average length of a coded symbol using any variable- length coding scheme