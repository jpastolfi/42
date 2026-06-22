import sys


class InvalidParameterError(Exception):
    def __init__(self, message: str) -> None:
        super().__init__(message)


if __name__ == "__main__":
    print("=== Inventory System Analysis ===")
    inventory: dict[str, int] = dict()
    for item in sys.argv[1:]:
        try:
            separator = item.find(":")
            if separator == -1:
                raise InvalidParameterError(item)
            name = item[:separator]
            if name in inventory:
                print("Redundant item '{}'- discarding".format(name))
                continue
            quantity = int(item[separator + 1:])
            inventory[name] = quantity

        except ValueError as e:
            print("Quantity error for '{}': {}".format(name, e))
        except InvalidParameterError as e:
            print("Error - invalid parameter {}".format(e))

    print("Got inventory: {}".format(inventory))
    print("Item list: {}".format(list(inventory.keys())))
    print("Total quantity of the {} items: {}"
          .format(len(inventory), sum(inventory.values())))

    for key, value in inventory.items():
        print("Item {} represents {}%"
              .format(key, round(value / sum(inventory.values()) * 100, 1)))

    if len(inventory.keys()) > 0:
        most: int = 0
        most_name: str = ""
        for key, value in inventory.items():
            if value > most:
                most = value
                most_name = key
        least: int = most
        least_name: str = ""
        for key, value in inventory.items():
            if value < least:
                least = value
                least_name = key
        print(
            "Item most abundant: {} with quantity {}"
            .format(most_name, most)
            )
        print(
            "Item least abundant: {} with quantity {}"
            .format(least_name, least)
            )

    inventory.update({
        "magic_item": 1
    })

    print("Updated inventory: {}".format(inventory))
