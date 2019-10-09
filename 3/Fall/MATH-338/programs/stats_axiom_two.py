#!/usr/bin/env python3.5

# probability can be calculated by using a hash table in conjunction with a set
# hash tables are used when there are two different letters with the same probability
# using a bare list would result in incorrect calculations of probability as they would be treated as non unique instances, in turn allowing for it to filter out needed objects

class hashabledict(dict):
    def __hash__(self):
        return hash(tuple(sorted(self.items())))
value_mapping = {
	"c": 0.02,
	"a": 0.09,
	"t": 0.06,
	"p": 0.02,
	"e": 0.12
}

def get_probability(*args):
	s = set((hashabledict({letter: value_mapping[letter]}) for argument in args for letter in argument))
	return sum([sum(dictionary.values()) for dictionary in s])


print(get_probability("cat", "pet"))
# this some times yields 0.310000000000005 and 0.3099999999999994 which is essentially the same number
