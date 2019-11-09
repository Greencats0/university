def find_missing(list_one: list, list_two: list):
	return list(set.difference(set(list_one), set(list_two)))

a = [1, 2, 3]
b = [2, 3]

print(find_missing(a, b))


def missing_non_stl(list_one: list, list_two: list):
	return [element for element in list_one if not(element in list_two)]

print(missing_non_stl(a, b))
