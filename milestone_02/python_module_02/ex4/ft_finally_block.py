class GardenError(Exception):
    def __init__(self, message: str = "Unknown garden error") -> None:
        self.message = message
        super().__init__(self.message)

    def __str__(self) -> str:
        return f"Error: {self.message}"


class PlantError(GardenError):
    def __init__(self, message: str = "Unknown plant error") -> None:
        super().__init__(message)


def water_plant(plant_name: str) -> None:
    if (plant_name != str.capitalize(plant_name)):
        raise PlantError(plant_name)
    print("Watering {}: OK".format(plant_name))


def test_watering_system(should_break: int = 0) -> None:
    print("=== Garden Watering System ===")
    print("Testing valid plants...")
    print("Opening watering system")
    try:
        water_plant("Tomato")
        water_plant("Lettuce")
        water_plant("Carrot")
        if should_break == 1:
            water_plant("potato")
    except PlantError as e:
        print(f"Caught PlantError: Invalid plant name to water: {e.message}")
    finally:
        print("Closing watering system", end="\n\n")


if (__name__ == "__main__"):
    test_watering_system()
    print("=== Testing errors ===")
    test_watering_system(1)
