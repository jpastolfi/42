import sys

class NotEnoughArgumentsException(Exception):
    def __init__(self, message: str = "Not enough arguments") -> None:
        super().__init__(message)
        self.message = message

if (__name__ == "__main__"):
    print("=== Player Score Analytics ===")
    try:
        storage: list[int] = list()
        for item in sys.argv[1:]:
            try:
                storage.append(int(item))
            except ValueError:
                print("Invalid parameter: {}".format(item))
        if len(storage) < 1:
            raise NotEnoughArgumentsException
        print("Scores processed: {}".format(storage))
        print("Total players: {}".format(len(storage)))
        print("Total score: {}".format(sum(storage)))
        print("Average score: {}".format(sum(storage) / len(storage)))
        print("High score: {}".format(max(storage)))
        print("Low score: {}".format(min(storage)))
        print("Score range: {}".format(max(storage) - min(storage)))
    except NotEnoughArgumentsException:
            print("No scores provided. Usage: python3 ft_score_analytics.py <score1> <score2> ...")
    