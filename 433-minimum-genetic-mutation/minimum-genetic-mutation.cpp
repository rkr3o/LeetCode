class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string> st(bank.begin(), bank.end()); // Create a set of valid gene mutations.
        queue<pair<string, int>> q;
        q.push({startGene, 0}); // Initialize the queue with the start gene and 0 mutations.
        st.erase(startGene); // Remove the start gene from the set since it's assumed to be valid.

        while (!q.empty()) {
            string gene = q.front().first;
            int mutations = q.front().second;
            q.pop();

            if (gene == endGene) {
                return mutations; // If we reached the end gene, return the number of mutations.
            }

            for (int i = 0; i < gene.size(); ++i) {
                char original = gene[i];
                for (char ch : {'A', 'C', 'G', 'T'}) {
                    if (ch == original) continue; // Skip the same character.
                    gene[i] = ch; // Mutate the gene by changing the character at position i.
                    if (st.find(gene) != st.end()) { // If the mutated gene is in the set, add it to the queue.
                        q.push({gene, mutations + 1}); // Increment the number of mutations.
                        st.erase(gene); // Remove the mutated gene from the set to avoid duplicate processing.
                    }
                }
                gene[i] = original; // Restore the original character for the next iteration.
            }
        }

        return -1; // If we reach here, there's no way to transform startGene into endGene.
    }
};