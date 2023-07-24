class CommandBase {
    protected:
        bool isCancelled = false;

    public:
        void execute ();
        void cancel ();

        virtual void run ();
        virtual bool isFinished ();
        virtual void onEnd (bool interrupted);
};
