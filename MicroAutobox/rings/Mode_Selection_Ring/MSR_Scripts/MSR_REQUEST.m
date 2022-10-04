classdef MSR_REQUEST < Simulink.IntEnumType
    enumeration
        OFF(0),
		STARTUP_LV(1),
        STARTUP_HV(2),
		RUNNING(3),
        SHUTDOWN_LV(4),
        SHUTDOWN_HV(5),
    end

    methods (Static)

        function defaultValue = getDefaultValue()
            % GETDEFAULTVALUE  Returns the default enumerated value.
            %   If this method is not defined, the first enumeration is used.
            defaultValue = MSR_REQUEST.OFF;
        end

        function dScope = getDataScope()
            % GETDATASCOPE  Specifies whether the data type definition should be imported from,
            %               or exported to, a header file during code generation.
            dScope = 'Exported';
        end

        function desc = getDescription()
            % GETDESCRIPTION  Returns a description of the enumeration.
            desc = 'Mode request made by the MSR for the other control rings.';
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