classdef DRIVE_MODE < Simulink.IntEnumType
    enumeration
        OFF(0),
        OPEN_DIFFERENTIAL(1)
		TORQUE_VECTORING_STABLE(2),
		TORQUE_VECTORING_UNSTABLE(3),
    end

    methods (Static)

        function defaultValue = getDefaultValue()
            % GETDEFAULTVALUE  Returns the default enumerated value.
            %   If this method is not defined, the first enumeration is used.
            defaultValue = DRIVE_MODE.OFF;
        end

        function dScope = getDataScope()
            % GETDATASCOPE  Specifies whether the data type definition should be imported from,
            %               or exported to, a header file during code generation.
            dScope = 'Exported';
        end

        function desc = getDescription()
            % GETDESCRIPTION  Returns a description of the enumeration.
            desc = 'Specifies the driving mode for the vehicle.';
        end

        function fileName = getHeaderFile()
            % GETHEADERFILE  Returns path to header file if non-empty.
            fileName = '';
        end

        function flag = addClassNameToEnumNames()
            % ADDCLASSNAMETOENUMNAMES  Indicate whether code generator applies the class name as a prefix
            %                          to the enumeration.
            flag = true;
        end
    end
end