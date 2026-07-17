from uuid import uuid4
from pydantic import BaseModel, Field, ValidationError
from datetime import date, datetime


class SpaceStation(BaseModel):
    station_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=1, max_length=50)
    crew_size: int = Field(ge=1, le=20)
    power_level: float = Field(ge=0.0, le=100.0)
    oxygen_level: float = Field(ge=0.0, le=100.0)
    last_maintenance: datetime
    is_operational: bool = True
    notes: str | None = Field(default=None, max_length=200)


def main():
    try:
        valid_spacestation = SpaceStation(
            station_id=uuid4().hex[:8],
            name="Death Star",
            crew_size=18,
            power_level=25.0,
            oxygen_level=50.0,
            last_maintenance=date(2023, 3, 1),
        )
        print("Space Station Data Validation")
        print("=============================================")
        print("Valid station created:")
        for item in valid_spacestation.model_dump().items():
            key, value = item
            print(f"{key.capitalize()}: {value}")
        print("=============================================")

        invalid_spacestation = SpaceStation(
            station_id=uuid4().hex[:8],
            name="",
            crew_size=365,
            power_level=25.0,
            oxygen_level=50.0,
            last_maintenance=date(2023, 3, 1),
        )
        print("Space Station Data Validation")
        print("=============================================")
        print("Valid station created:")
        for item in invalid_spacestation.model_dump().items():
            key, value = item
            print(f"{key.capitalize()}: {value}")
        print("=============================================")
    except ValidationError as e:
        for item in e.errors():
            print(f"Error in field '{item['loc'][0]}': {item['msg']}")


if __name__ == "__main__":
    main()
