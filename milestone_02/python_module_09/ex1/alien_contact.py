from random import randint, uniform
from datetime import datetime
from enum import Enum
from pydantic import BaseModel, model_validator, Field, ValidationError


class ContactType(Enum):
    radio = 1
    visual = 2
    physical = 3
    telepathic = 4


class AlienContact(BaseModel):
    contact_id: str = Field(min_length=5, max_length=15)
    timestamp: datetime
    location: str = Field(min_length=3, max_length=100)
    contact_type: ContactType
    signal_strength: float = Field(ge=0.0, le=10.0)
    duration_minutes: int = Field(ge=1, le=1440)
    witness_count: int = Field(ge=1, le=100)
    message_received: str | None = Field(default=None, max_length=500)
    is_verified: bool = False

    @model_validator(mode='after')
    def contact_id_validator(self):
        if not self.contact_id.startswith("AC"):
            raise ValueError(
                "Contact ID must start with \"AC\" (Alien Contact)"
                )
        return self

    @model_validator(mode='after')
    def physical_contact_validator(self):
        if (
            self.contact_type is ContactType.physical
            and self.is_verified is False
        ):
            raise ValueError(
                "Physical contact reports must be verified"
                )
        return self

    @model_validator(mode='after')
    def telepathic_contact_validator(self):
        if (self.contact_type is ContactType.telepathic
                and self.witness_count < 3):
            raise ValueError(
                "Telepathic contact requires at least 3 witnesses"
                )
        return self

    @model_validator(mode='after')
    def signal_strength_validator(self):
        if (self.signal_strength > 7.0 and self.message_received is None):
            raise ValueError(
                "Strong signals (> 7.0) should include received messages"
                )
        return self


def main():
    contact = AlienContact(
        contact_id="AC-001/2026",
        timestamp=datetime.now(),
        location="Lisboa",
        contact_type=ContactType.radio,
        signal_strength=round(uniform(0.0, 10.0), 2),
        duration_minutes=randint(1, 1440),
        witness_count=randint(1, 100),
        message_received="Take me to your leader",
        is_verified=True
    )
    print("Alien Contact Log Validation")
    print("======================================")
    print(f"ID: {contact.contact_id}")
    print(f"Type: {contact.contact_type.name}")
    print(f"Location: {contact.location}")
    print(f"Signal: {contact.signal_strength}/10")
    print(f"Duration: {contact.duration_minutes} minutes")
    print(f"Witnesses: {contact.witness_count}")
    if contact.message_received is not None:
        print(f"Message: '{contact.message_received}'")
    print("======================================")

    try:
        invalid_contact = AlienContact(
            contact_id="001/2026",
            timestamp=datetime.now(),
            location="Lisboa",
            contact_type=ContactType.physical,
            signal_strength=round(uniform(0.0, 10.0), 2),
            duration_minutes=randint(1, 1440),
            witness_count=randint(1, 100),
            message_received="Message",
            is_verified=True
        )
    except ValidationError as e:
        for item in e.errors():
            print(f"Error: {item['msg']}")

    try:
        invalid_contact = AlienContact(
            contact_id="AC-001/2026",
            timestamp=datetime.now(),
            location="Lisboa",
            contact_type=ContactType.physical,
            signal_strength=round(uniform(0.0, 10.0), 2),
            duration_minutes=randint(1, 1440),
            witness_count=randint(1, 100),
            message_received="Message",
        )
    except ValidationError as e:
        for item in e.errors():
            print(f"Error: {item['msg']}")

    try:
        invalid_contact = AlienContact(
            contact_id="AC-001/2026",
            timestamp=datetime.now(),
            location="Lisboa",
            contact_type=ContactType.telepathic,
            signal_strength=round(uniform(0.0, 10.0), 2),
            duration_minutes=randint(1, 1440),
            witness_count=2,
            message_received="Message",
            is_verified=True
        )
    except ValidationError as e:
        for item in e.errors():
            print(f"Error: {item['msg']}")

    try:
        invalid_contact = AlienContact(
            contact_id="AC-001/2026",
            timestamp=datetime.now(),
            location="Lisboa",
            contact_type=ContactType.physical,
            signal_strength=7.1,
            duration_minutes=randint(1, 1440),
            witness_count=randint(1, 100),
            is_verified=True
        )
        print(invalid_contact)
    except ValidationError as e:
        for item in e.errors():
            print(f"Error: {item['msg']}")


if __name__ == "__main__":
    main()
