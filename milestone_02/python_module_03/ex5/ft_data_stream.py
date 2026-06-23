import typing
import random

names_list: list[str] = ["bob", "alice", "dylan", "charlie"]
actions_list: list[str] = ["run", "eat", "sleep", "grab",
                           "move", "climb", "swim", "release"]


def gen_event() -> typing.Generator[tuple[str, str], None, None]:
    yield (random.choice(names_list), random.choice(actions_list))


def consume_event(
        my_list: list[tuple[str, str]]
        ) -> typing.Generator[tuple[str, str], None, None]:
    yield my_list.pop(random.randrange(len(my_list)))


if __name__ == "__main__":
    print("=== Game Data Stream Processor ===")
    for index in range(1000):
        name, event = next(gen_event())
        print("Event {}: Player {} did action {}".format(index, name, event))

    my_list = [next(gen_event()) for _i in range(10)]
    print("Built list of 10 events: {}".format(my_list))

    for _i in range(10):
        print("Got event from list: {}".format(next(consume_event(my_list))))
        print("Remains in list: {}".format(my_list))
