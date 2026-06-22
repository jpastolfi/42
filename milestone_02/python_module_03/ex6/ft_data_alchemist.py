import random

initial_names_list: list[str] = [
    'Alice', 'bob', 'Charlie', 'dylan',
    'Emma', 'Gregory', 'john', 'kevin', 'Liam'
    ]
initial_capitalized: list[str] = [
    name.capitalize() for name in initial_names_list
    ]
initial_capitalized_only: list[str] = [
    name for name in initial_names_list if name[0].isupper()
    ]
score_dict: dict[str, int] = {
    name: random.randint(0, 1000) for name in initial_capitalized
    }
average: float = round(sum(score_dict.values()) / len(score_dict), 2)
high_scores: dict[str, int] = {
    name: score for name, score in score_dict.items() if score > average
    }


if __name__ == "__main__":
    print("Initial list of players: {}".format(initial_names_list))
    print("New list with all names capitalized: {}"
          .format(initial_capitalized))
    print("New list of capitalized names only: {}"
          .format(initial_capitalized_only))
    print("Score dict: {}".format(score_dict))
    print("Score average is {}".format(average))
    print("High scores: {}".format(high_scores))
