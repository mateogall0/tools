#!/usr/bin/env python3
from sqlalchemy import DateTime, Column, String
import uuid
from datetime import datetime
from sqlalchemy.orm import declarative_base
Base = declarative_base()
from typing import List


class BaseModel(Base):
    """
    Base model used for many use cases using SQLAlchemy.
    
    This is intended to be the top abstract class when creating models,
    including a to_dict method that turns the entire model to a dictionary
    that excludes certain keys, declared in a list of strings. For instance if
    you are working in an API and want to return all data from a user, you can
    declare specific keys that you want to not be included, like the password
    hash.
    """
    __abstract__ = True
    id = Column(String(36), primary_key=True, default=uuid.uuid4, unique=True, nullable=False)
    created_at = Column(DateTime, default=datetime.utcnow, nullable=False)
    updated_at = Column(DateTime, default=datetime.utcnow, nullable=False)

    _exclude_keys: List[str] = []

    def to_dict(self) -> dict:
        columns = [column.name for column in self.__table__.columns if column.name not in self._exclude_keys]
        return {column: getattr(self, column) for column in columns}
