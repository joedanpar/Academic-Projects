import java.io.Serializable;

public class MessageObject implements Serializable {
	String transtype, name, ssn, address;
	int code;
	public MessageObject(){
		
	}
	public MessageObject(String name, String ssn, String address, int code2) {
		this.name = name;
		this.ssn = ssn;
		this.address = address;
		this.code = code2;
	}
	void setTransType(String s){
		transtype = s;
	}
	String getTransType(){
		return transtype;
	}
	String getName(){
		return name;
	}
	/**
	 * @return the transtype
	 */
	public String getTranstype() {
		return transtype;
	}
	/**
	 * @param transtype the transtype to set
	 */
	public void setTranstype(String transtype) {
		this.transtype = transtype;
	}
	/**
	 * @return the ssn
	 */
	public String getSsn() {
		return ssn;
	}
	/**
	 * @param ssn the ssn to set
	 */
	public void setSsn(String ssn) {
		this.ssn = ssn;
	}
	/**
	 * @return the address
	 */
	public String getAddress() {
		return address;
	}
	/**
	 * @param address the address to set
	 */
	public void setAddress(String address) {
		this.address = address;
	}
	/**
	 * @return the code
	 */
	public int getCode() {
		return code;
	}
	/**
	 * @param code the code to set
	 */
	public void setCode(int code) {
		this.code = code;
	}
	/**
	 * @param name the name to set
	 */
	public void setName(String name) {
		this.name = name;
	}
}