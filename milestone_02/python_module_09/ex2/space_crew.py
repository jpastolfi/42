from sys import exit
from enum import Enum
from datetime import datetime
from pydantic import BaseModel, Field, model_validator, ValidationError


class Rank(Enum):
    cadet = 1
    officer = 2
    lieutenant = 3
    captain = 4
    commander = 5


class CrewMember(BaseModel):
    member_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=2, max_length=50)
    rank: Rank
    age: int = Field(ge=18, le=80)
    specialization: str = Field(min_length=3, max_length=30)
    years_experience: int = Field(ge=0, le=50)
    is_active: bool = True


class SpaceMission(BaseModel):
    mission_id: str = Field(min_length=5, max_length=15)
    mission_name: str = Field(min_length=3, max_length=100)
    destination: str = Field(min_length=3, max_length=50)
    launch_date: datetime
    duration_days: int = Field(ge=1, le=3650)
    crew: list[CrewMember] = Field(min_length=1, max_length=12)
    mission_status: str = "planned"
    budget_millions: float = Field(ge=1.0, le=10000.0)

    @model_validator(mode="after")
    def mission_id_validator(self):
        # Mission ID must start with "M"
        if not self.mission_id.startswith("M"):
            raise ValueError(
                "Mission ID must start with 'M'"
            )
        return self

    @model_validator(mode="after")
    def commander_or_captain_validator(self):
        # Must have at least one Commander or Captain
        for member in self.crew:
            if member.rank == Rank.captain or member.rank == Rank.commander:
                return self
        raise ValueError(
            "Must have at least one Commander or Captain"
        )

    @model_validator(mode="after")
    # Long missions (> 365 days) need 50% experienced crew (5+ years)
    def mission_duration_validator(self):
        counter = 0
        if self.duration_days > 365:
            for member in self.crew:
                if member.years_experience > 5:
                    counter += 1
            if counter / len(self.crew) < 0.50:
                raise ValueError(
                    "Long missions (> 365 days)",
                    "need 50% experienced crew (5+ years)"
                )
        return self

    @model_validator(mode="after")
    def active_crew_validator(self):
        # All crew members must be active
        for member in self.crew:
            if member.is_active is False:
                raise ValueError(
                    "All crew members must be active"
                )
        return self


def main():
    try:
        crew_members = [
            CrewMember(
                member_id="CM001",
                name="Ana Ferreira",
                rank=Rank.cadet,
                age=45,
                specialization="Navigation",
                years_experience=22,
                is_active=True
            ),
            CrewMember(
                member_id="CM002",
                name="Bruno Silva",
                rank=Rank.officer,
                age=29,
                specialization="Engineering",
                years_experience=6,
                is_active=True
            ),
            CrewMember(
                member_id="CM003",
                name="Carla Mendes",
                rank=Rank.lieutenant,
                age=19,
                specialization="Medical",
                years_experience=0,
                is_active=True
            ),
            CrewMember(
                member_id="CM004",
                name="Diogo Costa",
                rank=Rank.captain,
                age=61,
                specialization="Propulsion Systems",
                years_experience=38,
                is_active=True
            ),
            CrewMember(
                member_id="CM005",
                name="Elisa Rocha",
                rank=Rank.commander,
                age=80,
                specialization="Communications",
                years_experience=50,
                is_active=True
            ),
        ]
    except ValidationError as e:
        print("Error in CrewMember creation: ", end="")
        for error in e.errors():
            print(error['msg'])
        exit(0)

    # --- valid mission (should succeed) --------------------------------
    try:
        mission = SpaceMission(
            mission_id="MARS-2031",
            mission_name="Ares Horizon: Crewed Mars Transit Mission",
            destination="Mars Orbit",
            launch_date=datetime(2031, 3, 14, 9, 30, 0),
            duration_days=940,
            crew=crew_members,
            mission_status="planned",
            budget_millions=8750.5
        )
        print("Valid mission created:", mission.mission_id)
    except ValidationError as e:
        print("Failure on valid mission:", e.errors()[0]["msg"])

    # --- mission_id_validator: id doesn't start with 'M' ----------------
    try:
        SpaceMission(
            mission_id="XARS-2031",
            mission_name="Ares Horizon: Crewed Mars Transit Mission",
            destination="Mars Orbit",
            launch_date=datetime(2031, 3, 14, 9, 30, 0),
            duration_days=940,
            crew=crew_members,
            mission_status="planned",
            budget_millions=8750.5
        )
        print("ERROR: mission with bad id should have failed")
    except ValidationError as e:
        print("OK - mission_id_validator caught it:", e.errors()[0]["msg"])

    # --- commander_or_captain_validator: no captain/commander -----------
    crew_no_leadership = [
        CrewMember(member_id="CM001", name="Ana Ferreira", rank=Rank.cadet,
                   age=45, specialization="Navigation", years_experience=22,
                   is_active=True),
        CrewMember(member_id="CM002", name="Bruno Silva", rank=Rank.officer,
                   age=29, specialization="Engineering", years_experience=6,
                   is_active=True),
    ]
    try:
        SpaceMission(
            mission_id="MARS-2031",
            mission_name="Ares Horizon: Crewed Mars Transit Mission",
            destination="Mars Orbit",
            launch_date=datetime(2031, 3, 14, 9, 30, 0),
            duration_days=940,
            crew=crew_no_leadership,
            mission_status="planned",
            budget_millions=8750.5
        )
        print("ERROR: mission with no captain/commander should have failed")
    except ValidationError as e:
        print("OK - commander_or_captain_validator caught it:",
              e.errors()[0]["msg"])

    # --- mission_duration_validator: long mission, not enough experience --
    crew_junior = [
        CrewMember(member_id="CM001", name="Ana Ferreira", rank=Rank.commander,
                   age=45, specialization="Navigation", years_experience=2,
                   is_active=True),
        CrewMember(member_id="CM002", name="Bruno Silva", rank=Rank.officer,
                   age=29, specialization="Engineering", years_experience=3,
                   is_active=True),
        CrewMember(member_id="CM003", name="Carla Mendes",
                   rank=Rank.lieutenant, age=19, specialization="Medical",
                   years_experience=1, is_active=True),
    ]
    try:
        SpaceMission(
            mission_id="MARS-2031",
            mission_name="Ares Horizon: Crewed Mars Transit Mission",
            destination="Mars Orbit",
            launch_date=datetime(2031, 3, 14, 9, 30, 0),
            duration_days=940,
            crew=crew_junior,
            mission_status="planned",
            budget_millions=8750.5
        )
        print("ERROR: long mission with junior crew should have failed")
    except (ValidationError, UnboundLocalError) as e:
        print("OK - mission_duration_validator caught it:",
              e.errors()[0]["msg"])

    # --- active_crew_validator: one inactive member ----------------------
    crew_inactive = [
        CrewMember(member_id="CM001", name="Ana Ferreira", rank=Rank.commander,
                   age=45, specialization="Navigation", years_experience=22,
                   is_active=True),
        CrewMember(member_id="CM002", name="Bruno Silva", rank=Rank.officer,
                   age=29, specialization="Engineering", years_experience=6,
                   is_active=False),
    ]
    try:
        SpaceMission(
            mission_id="MARS-2031",
            mission_name="Ares Horizon: Crewed Mars Transit Mission",
            destination="Mars Orbit",
            launch_date=datetime(2031, 3, 14, 9, 30, 0),
            duration_days=940,
            crew=crew_inactive,
            mission_status="planned",
            budget_millions=8750.5
        )
        print("ERROR: mission with inactive crew member should have failed")
    except ValidationError as e:
        print("OK - active_crew_validator caught it:", e.errors()[0]["msg"])
    except Exception as e:
        print(e)


if __name__ == "__main__":
    main()
