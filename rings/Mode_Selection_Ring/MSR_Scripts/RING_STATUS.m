classdef RING_STATUS < Simulink.IntEnumType
    enumeration
        OFF(0),
		STARTUP_IN_PROGRESS_LV(1),
		STARTUP_COMPLETE_LV(2),
        STARTUP_IN_PROGRESS_HV(3),
		STARTUP_COMPLETE_HV(4),
        RUNNING(5),
        SHUTDOWN_IN_PROGRESS_LV(6),
		SHUTDOWN_COMPLETE_LV(7),
        SHUTDOWN_IN_PROGRESS_HV(8),
		SHUTDOWN_COMPLETE_HV(9),
    end

    methods (Static)

        function defaultValue = getDefaultValue()
            % GETDEFAULTVALUE  Returns the default enumerated value.
            %   If this method is not defined, the first enumeration is used.
            defaultValue = RING_STATUS.OFF;
        end

        function dScope = getDataScope()
            % GETDATASCOPE  Specifies whether the data type definition should be imported from,
            %               or exported to, a header file during code generation.
            dScope = 'Exported';
        end

        function desc = getDescription()
            % GETDESCRIPTION  Returns a description of the enumeration.
            desc = 'Specifies the operating mode for a control ring.';
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