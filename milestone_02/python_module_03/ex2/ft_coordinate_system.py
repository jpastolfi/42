import math


def get_player_pos() -> tuple[float, float, float]:
    print("Enter new coordinates as float: ")
    while True:
        try:
            x: float = float(input("X: "))
            y: float = float(input("Y: "))
            z: float = float(input("Z: "))
            break
        except ValueError:
            print("Invalid syntax")
    gps_position: tuple[float, float, float] = (x, y, z)
    return gps_position


def display_tuple(position: tuple[float, float, float],
                  is_first: bool = True) -> None:
    print("Got a {} tuple: {}"
          .format("first" if is_first else "second", position))
    print("It includes: X={}, Y={}, Z={}"
          .format(position[0], position[1], position[2]))


def pow_two(n: float) -> float:
    return n * n


def calculate_distance(
        first_position: tuple[float, float, float],
        second_position: tuple[float, float, float]) -> float:
    return round(math.sqrt(
        pow_two(first_position[0] - second_position[0]) +
        pow_two(first_position[1] - second_position[1]) +
        pow_two(first_position[2] - second_position[2])
    ), 4)


if __name__ == "__main__":
    first_position: tuple[float, float, float] = get_player_pos()
    display_tuple(first_position)
    print("Distance to center: {}"
          .format(calculate_distance(first_position, (0, 0, 0))))
    second_position: tuple[float, float, float] = get_player_pos()
    display_tuple(second_position, False)
    print("Distance between the 2 sets of coordinates: {}"
          .format(calculate_distance(first_position, second_position)))
