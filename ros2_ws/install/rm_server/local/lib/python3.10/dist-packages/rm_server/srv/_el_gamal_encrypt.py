# generated from rosidl_generator_py/resource/_idl.py.em
# with input from rm_server:srv/ElGamalEncrypt.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ElGamalEncrypt_Request(type):
    """Metaclass of message 'ElGamalEncrypt_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('rm_server')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rm_server.srv.ElGamalEncrypt_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__el_gamal_encrypt__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__el_gamal_encrypt__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__el_gamal_encrypt__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__el_gamal_encrypt__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__el_gamal_encrypt__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ElGamalEncrypt_Request(metaclass=Metaclass_ElGamalEncrypt_Request):
    """Message class 'ElGamalEncrypt_Request'."""

    __slots__ = [
        '_b',
    ]

    _fields_and_field_types = {
        'b': 'int64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.b = kwargs.get('b', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.b != other.b:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def b(self):
        """Message field 'b'."""
        return self._b

    @b.setter
    def b(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'b' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'b' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._b = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ElGamalEncrypt_Response(type):
    """Metaclass of message 'ElGamalEncrypt_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('rm_server')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rm_server.srv.ElGamalEncrypt_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__el_gamal_encrypt__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__el_gamal_encrypt__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__el_gamal_encrypt__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__el_gamal_encrypt__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__el_gamal_encrypt__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ElGamalEncrypt_Response(metaclass=Metaclass_ElGamalEncrypt_Response):
    """Message class 'ElGamalEncrypt_Response'."""

    __slots__ = [
        '_y1',
        '_y2',
    ]

    _fields_and_field_types = {
        'y1': 'int64',
        'y2': 'int64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.y1 = kwargs.get('y1', int())
        self.y2 = kwargs.get('y2', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.y1 != other.y1:
            return False
        if self.y2 != other.y2:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def y1(self):
        """Message field 'y1'."""
        return self._y1

    @y1.setter
    def y1(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'y1' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'y1' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._y1 = value

    @builtins.property
    def y2(self):
        """Message field 'y2'."""
        return self._y2

    @y2.setter
    def y2(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'y2' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'y2' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._y2 = value


class Metaclass_ElGamalEncrypt(type):
    """Metaclass of service 'ElGamalEncrypt'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('rm_server')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'rm_server.srv.ElGamalEncrypt')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__el_gamal_encrypt

            from rm_server.srv import _el_gamal_encrypt
            if _el_gamal_encrypt.Metaclass_ElGamalEncrypt_Request._TYPE_SUPPORT is None:
                _el_gamal_encrypt.Metaclass_ElGamalEncrypt_Request.__import_type_support__()
            if _el_gamal_encrypt.Metaclass_ElGamalEncrypt_Response._TYPE_SUPPORT is None:
                _el_gamal_encrypt.Metaclass_ElGamalEncrypt_Response.__import_type_support__()


class ElGamalEncrypt(metaclass=Metaclass_ElGamalEncrypt):
    from rm_server.srv._el_gamal_encrypt import ElGamalEncrypt_Request as Request
    from rm_server.srv._el_gamal_encrypt import ElGamalEncrypt_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
