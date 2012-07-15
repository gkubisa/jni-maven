package ie.agisoft;

class Test {

	public native void hello();

	static {
		try {
			LibraryLoader.loadLibrary("agisoft");
		} catch (Exception e) {
			System.err.println(e);
			System.exit(1);
		}
	}
}