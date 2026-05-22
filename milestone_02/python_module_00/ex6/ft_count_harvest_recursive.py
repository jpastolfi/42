def ft_count_harvest_recursive() -> None:
    days_until: int = int(input("Days until harvest: "))
    if (days_until <= 0):
        return
    recursive_print(days_until)

def recursive_print(days_until: int) -> None:
    if days_until == 0:
        print("Harvest time!")
        return
    print("Day {}".format(days_until))
    recursive_print(days_until - 1)