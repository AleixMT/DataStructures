public class AirportInfo implements Comparable<AirportInfo>{

    private String identificador;
    private String[] geographicPosition = new String[2];

    public AirportInfo(String identificador, String posGeographic1, String posGeographic2) {
        this.identificador = identificador;
        this.geographicPosition = new String[]{posGeographic1, posGeographic2};
    }

    @Override
    public int compareTo(AirportInfo o) {
        return this.identificador.compareTo(o.identificador);
    }

}
