class Plant:
    def __init__(self, name: str, height: float, age_days: int) -> None:
        self.name = name
        self.height = round(height, ndigits=4)
        self.age_days = age_days

    def show(self) -> None:
        print("{}: {:.1f}cm, {} days old"
              .format(self.name, self.height, self.age_days))


def ft_garden_data() -> None:
    print("=== Garden Plant Registry ===")
    plant = Plant("Rose", 25, 30)
    plant.show()
    plant = Plant("Sunflower", 80, 45)
    plant.show()
    plant = Plant("Cactus", 15, 120)
    plant.show()
