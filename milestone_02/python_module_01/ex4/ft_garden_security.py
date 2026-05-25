class Plant:
    def __init__(self, name: str, height: float, age_days: int) -> None:
        self._name = name
        self.set_name(name)
        if height < 0:
            print("{}: Error, height can't be negative"
                  .format(self.get_name()))
            return
        self._height = height
        if age_days < 0:
            print("{}: Error, age can't be negative"
                  .format(self.get_name()))
            return
        self._age_days = age_days
        self.ratio = self._height / self._age_days
        print("Plant created: ", end="")
        self.show()

    def get_name(self) -> str:
        return self._name

    def set_name(self, name: str) -> None:
        self._name = name

    def get_height(self) -> float:
        return self._height

    def set_height(self, height: float) -> None:
        if height < 0:
            print("""{}: Error, height can't be negative
Height update rejected""". format(self.get_name()))
        else:
            self._height = height
            print("Height updated: {}cm".format(self.get_height()))

    def get_age_days(self) -> int:
        return self._age_days

    def set_age_days(self, age_days: int) -> None:
        if age_days < 0:
            print("""{}: Error, age can't be negative
Age update rejected""". format(self.get_name()))
        else:
            self._age_days = age_days
            print("Age updated: {} days".format(self.get_age_days()))

    def show(self) -> None:
        print("{}: {:.1f}cm, {} days old"
              .format(self._name, self._height, self._age_days))

    def grow(self) -> None:
        total_growth = 0.0
        for i in range(1, 8):
            total_growth += round(self.ratio, 1)
            print("=== Day {} ===".format(i))
            self._height = round(self._height + self.ratio, 1)
            self.age(1)
            self.show()
        print("Growth this week: {}cm".format(total_growth))

    def age(self, days: int) -> None:
        if days < 0:
            print("""{}: Error, age can't be negative
Age update rejected""". format(self.get_name()))
        self._age_days += days


def ft_garden_security():
    plant = Plant("Fern", 15.0, 120)
    plant.set_height(20)
    plant.set_height(-20)
    plant.show()
    plant = Plant("Rose", 15.0, 120)
    plant.set_age_days(150)
    plant.set_age_days(-150)
    plant.show()
