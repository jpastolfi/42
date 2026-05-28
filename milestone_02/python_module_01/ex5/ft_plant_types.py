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

class Flower(Plant):
    def __init__(self, name: str, height: float, age_days: int, color: str, has_bloomed: bool) -> None:
        self.color = color
        self.has_bloomed = has_bloomed
        super().__init__(name, height, age_days)

    def bloom(self) -> None:
        print("[asking the {} to bloom]".format(self._name))
        self.has_bloomed = True

    def show(self):
        super().show()
        print("Color: {}".format(self.color))
        print(("{} has not bloomed yet" if not self.has_bloomed else "{} is blooming beautifully!")
              .format(self._name))


class Tree(Plant):
    def __init__(self, name: str, height: float, age_days: int, trunk_diameter: float) -> None:
        self._trunk_diameter = trunk_diameter
        super().__init__(name, height, age_days)
    
    def produce_shade(self):
        print("[asking the {} to produce shade]".format(self._name))
        print("Tree {} now produces a shade of {}cm long and {}cm wide."
              .format(self._name, self._height, self._trunk_diameter))

    def show(self):
        super().show()
        print("Trunk diameter: {}".format(self._trunk_diameter))

class Vegetable(Plant):
    def __init__(self, name: str, height: float, age_days: int, harvest_season: str) -> None:
        self._harvest_season = harvest_season
        self._nutrition_days = 0
        super().__init__(name, height ,age_days)

    def nutritional_values(self, days: int):
        print("[make {} grow and age for {} days]".format(self._name, days))
        self._age_days += days 
        self._height += self._age_days
        self._nutrition_days += days
    
    def show(self):
        super().show()
        print("Harvest season: {}".format(self._harvest_season))
        print("Nutritional value: {}".format(self._nutrition_days))

def main():
    print("=== Garden Plant Types ===")
    print("=== Flower")
    flower = Flower("Rose", 15, 10, "Purple", False)
    flower.bloom()
    flower.show()
    print("=== Tree")
    tree = Tree("Oak", 200.0, 365, 5.0)
    tree.produce_shade()
    print("=== Vegetable")
    vegetable = Vegetable("Tomato", 5.0, 10, "April")
    vegetable.nutritional_values(20)
    vegetable.show()

if (__name__ == "__main__"):
    main()