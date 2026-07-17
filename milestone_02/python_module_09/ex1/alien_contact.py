from datetime import datetime
from enum import Enum
from pydantic import BaseModel, model_validator, constr, conint


class ContactType(Enum):
    radio = 1
    visual = 2
    physical = 3
    telepathic = 4


class AlienContact(BaseModel):
    contact_id: constr(min_length=5, max_length=15)
    timestamp: datetime  # DateTime of contact
    location: constr(min_length=3, max_length=100)
    contact_type: ContactType
    signal_strength: float  # 0.0-10.0 scale
    duration_minutes: int  # 1-1440 (max 24 hours)
    witness_count: int  # 1-100 people
    message_received: str = ""  # max 500 characters
    is_verified: bool = False

    @model_validator(mode='after')
    def contact_id_validator(cls, model):
        if not model.contact_id.startswith("AC"):
            raise ValueError(
                "Contact ID must start with \"AC\" (Alien Contact)"
                )

    @model_validator(mode='after')
    def telepathic_contact_validator(cls, model):
        if (model.contact_type is ContactType.telepathic
                and model.witness_count < 3):
            raise ValueError(
                "Telepathic contact requires at least 3 witnesses"
                )


print("ACFDFDF".startswith("AC"))
